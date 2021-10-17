#include "ButtonMark.h"
#include "cmath"
#include <algorithm>

bool is_button_mark(msg_data msg) {
	if (msg.id == 0xffff) return true;
	return false;
}

std::vector<msg_data> get_all_marks_from_msgs(std::vector<msg_data> msgs) {
	std::vector<msg_data> result;
	for (auto it = msgs.begin(); it != msgs.end(); it++) {
		if (is_button_mark(*it)) {
			if (result.size() == 0) {
				result.push_back(*it);
			} else if (std::abs((int)(it->time - result.back().time)) > 500) {
				int last_time = result.back().time;
				int current_time = it->time;
				result.push_back(*it);
			}
		}
	}
	sort(result.begin(), result.end(), [](msg_data& a, msg_data& b) -> bool {return a.time > b.time; });
	return result;
}