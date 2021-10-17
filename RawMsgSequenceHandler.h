#pragma once
#include "MsgSequenceHandler.h"


class RawMsgSequinceHandler : public MsgSequenceHandler {
public:
	void init_with_msg_data(std::vector<msg_data> msgs);
	virtual std::vector<std::pair<uint32_t, uint8_t> > get_byte_sequence(uint32_t msg_id, uint8_t byte_number) override;
	virtual std::vector<change_point> get_changes_sequence(uint32_t msg_id, uint8_t byte_number) override;
	virtual void print_data() override;
};