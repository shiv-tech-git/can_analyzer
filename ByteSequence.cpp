#include "ByteSequence.h"

#define MSG_DELAY 1000


void ByteSequence::add_change_point(MSG_TIME_T time, bool edge) {
	change_point cp = {
		time,
		0xff,
		edge
	};
	changes_points.push_back(cp);
}

void ByteSequence::find_changes() {
	uint8_t last_value = 0;
	auto it = msg_bytes.begin();
	last_value = it->second;
	uint32_t time = 0;
	uint8_t value = 0;

	time = it->first;
	//if first msg arives after start reading with delay
	if (time > MSG_DELAY) {
		changes_counter++;
		add_change_point(
			time,
			LEADING_EDGE
		);
	}
	it++;

	for (; it != msg_bytes.end(); it++) {
		time = it->first;
		value = it->second;

		//if value changed
		if (value != last_value) {
			changes_counter++;
			add_change_point(
				time,
				(int)(value > last_value ? LEADING_EDGE : TRAILING_EDGE)
			);
			last_value = value;
		}
		//if we have delay after this msg
		if (std::next(it) != msg_bytes.end() && (std::next(it)->first - time) > MSG_DELAY) {
			changes_counter++;
			add_change_point(
				time,
				TRAILING_EDGE
			);
		}
		//if we have delay before this msg
		if ((time - std::prev(it)->first) > MSG_DELAY) {
			changes_counter++;
			add_change_point(
				time,
				LEADING_EDGE
			);
		}
	}
}