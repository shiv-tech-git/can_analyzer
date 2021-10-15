#pragma once
#include <vector>
#include <unordered_map>

#include "MsgSequence.h"

class DataFormatter {
public:
	std::vector<uint32_t> get_msg_ids(std::unordered_map<uint32_t, MsgSequence*>& msg_sequenses);

};