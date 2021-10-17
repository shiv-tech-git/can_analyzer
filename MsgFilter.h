#pragma once
#include <vector>

#include "DataStructures.h"

class MsgFilter {
public:
	std::vector<MSG_ID_T> get_msgs_with_pulses_near_mark(int mark_number);
};