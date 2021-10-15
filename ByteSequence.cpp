#include "ByteSequence.h"


void ByteSequence::find_changes() {
	uint8_t last_value = 0;
	auto it = msg_bytes.begin();
	last_value = it->second;
	it++;
	uint32_t time = 0;
	uint8_t value = 0;
	for (; it != msg_bytes.end(); it++) {
		time = it->first;
		value = it->second;
		if (value == last_value) continue;

		changes_counter++;
		change_point cp = {
			time,
			value,
			(int)(value > last_value ? LEADING_EDGE : TRAILING_EDGE)
		};
		last_value = value;
	}
}