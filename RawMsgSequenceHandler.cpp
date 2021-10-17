#include "RawMsgSequenceHandler.h"
#include <iostream>
#include "ButtonMark.h"

void RawMsgSequinceHandler::init_with_msg_data(std::vector<msg_data> msgs) {
	for (auto it = msgs.begin(); it != msgs.end(); it++) {
		auto _it = msg_sequenses.find(it->id);
		if (is_button_mark(*it)) continue;

		if (_it == msg_sequenses.end()) {
			msg_sequenses[it->id] = new MsgSequence(it->id);
		}
		msg_sequenses[it->id]->add_msg(*it);
	}
	marks = get_all_marks_from_msgs(msgs);
	for (auto it = msg_sequenses.begin(); it != msg_sequenses.end(); it++) {
		auto test = it->second;
		it->second->find_changes();
	}
}

std::vector<std::pair<uint32_t, uint8_t> > RawMsgSequinceHandler::get_byte_sequence(uint32_t msg_id, uint8_t byte_number) {
	return msg_sequenses[msg_id]->get_byte_sequence(byte_number);
}

std::vector<change_point> RawMsgSequinceHandler::get_changes_sequence(uint32_t msg_id, uint8_t byte_number) {
	return msg_sequenses[msg_id]->get_changes_sequence(byte_number);
}

void RawMsgSequinceHandler::print_data() {
	std::cout << "print raw data" << std::endl;
}