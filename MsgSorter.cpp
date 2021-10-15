#include "MsgSorter.h"


std::map<CHANGES_COUNTER_T, MsgSequence*> MsgSorter::sort_by_changes(std::unordered_map<MSG_ID_T, MsgSequence*>& msg_sequenses) {
	std::map<MSG_ID_T, MsgSequence*> result;
	for (auto it = msg_sequenses.begin(); it != msg_sequenses.end(); it++) {
		result.insert(std::pair<CHANGES_COUNTER_T, MsgSequence*>(it->second->changes_counter, it->second));
	}
	return result;
}