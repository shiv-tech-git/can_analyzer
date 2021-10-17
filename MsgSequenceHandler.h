#pragma once
#include <unordered_map>
#include <vector>

#include "MsgSequence.h"
#include "DataStructures.h"

class MsgSequenceHandler {
public:
	std::unordered_map<MSG_ID_T, MsgSequence*> msg_sequenses;
	std::vector<msg_data> marks;

	virtual std::vector<std::pair<MSG_TIME_T, MSG_BYTE_T> > get_byte_sequence(MSG_ID_T msg_id, uint8_t byte_number) = 0;
	virtual std::vector<change_point> get_changes_sequence(MSG_ID_T msg_id, uint8_t byte_number) = 0;
	virtual void print_data() = 0;
};