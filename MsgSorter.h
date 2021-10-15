#pragma once
#include <vector>
#include <map>
#include <unordered_map>

#include "DataStructures.h"
#include "MsgSequence.h"

class MsgSorter {
public:
	std::map<MSG_ID_T, MsgSequence*> sort_by_changes(std::unordered_map<MSG_ID_T, MsgSequence*>& msg_sequenses);
};