#pragma once
#include <vector>

#include "DataStructures.h"
#include "RawMsgSequenceHandler.h"

class MsgFilter {
public:
	MsgFilter(RawMsgSequenceHandler* ms_handler);
	std::vector<MSG_ID_T> get_ids_with_pulse_near_mark(int mark);
	std::vector<MSG_ID_T> get_ids_with_pulse_near_marks(int mark1, int mark2);
	std::vector<MSG_ID_T> get_ids_with_leading_edge_near_mark(int mark);
	std::vector<MSG_ID_T> get_ids_with_falling_edge_near_mark(int mark);

private:
	RawMsgSequenceHandler* ms_handler;
};