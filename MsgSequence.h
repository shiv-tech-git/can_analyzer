#pragma once
#include "DataStructures.h"
#include "ByteSequence.h"
#include <vector>
#include <map>

class MsgSequence {
public:
	uint32_t msg_id;
	uint16_t changes_counter = 0;
	std::vector<ByteSequence*> b_seq;

	MsgSequence(uint32_t msg_id);
	~MsgSequence();
	void add_msg(msg_data&);
	void find_changes();
	std::vector<std::pair<uint32_t, uint8_t> > get_byte_sequence(uint8_t byte_number);
	std::vector<change_point> get_changes_sequence(uint8_t byte_number);

private:

	
};