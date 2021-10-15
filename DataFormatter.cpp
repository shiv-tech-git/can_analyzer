#include "DataFormatter.h"


std::vector<uint32_t> DataFormatter::get_msg_ids(std::unordered_map<uint32_t, MsgSequence*>& msg_sequenses) {
	std::vector<uint32_t> result;
	result.reserve(msg_sequenses.size());
	for (auto it = msg_sequenses.begin(); it != msg_sequenses.end(); it++) {
		result.push_back(it->first);
	}
	return result;
}