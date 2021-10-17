#pragma once
#include <vector>
#include <map>

#include "DataStructures.h"


class ByteSequence {
public:
	std::map<MSG_TIME_T, MSG_BYTE_T> msg_bytes;
	std::vector<change_point> changes_points;
	uint16_t changes_counter = 0;

	void find_changes();
	uint32_t length();
	void add_change_point(MSG_TIME_T time, bool edge);
};