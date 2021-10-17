#pragma once
#include "MsgSequenceHandler.h"
#include "DataStructures.h"


class RawMsgSequenceHandler : public MsgSequenceHandler {
public:
	void init_with_msg_data(std::vector<msg_data> msgs);
	std::vector<std::pair<uint32_t, uint8_t> > get_byte_sequence(uint32_t msg_id, uint8_t byte_number) ;
	std::vector<change_point> get_changes_sequence(uint32_t msg_id, uint8_t byte_number) ;
	void print_data();
	std::vector<MSG_ID_T> get_all_ids();
};