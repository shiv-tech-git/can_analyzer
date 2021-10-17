#include <iostream>

#include "CommandProcessor.h"
#include "MsgSorter.h"
#include <string>

CommandProcessor::CommandProcessor(MsgSequenceHandler* msh) : ms_handler(msh) {
	d_formatter = new DataFormatter();
	m_sorter = new MsgSorter();
}

CommandProcessor::~CommandProcessor() {
	delete d_formatter;
	delete m_sorter;
}

void CommandProcessor::print_msg_ids() {
	std::vector<uint32_t> msg_ids = d_formatter->get_msg_ids(ms_handler->msg_sequenses);
	for (auto it = msg_ids.begin(); it != msg_ids.end(); it++) {
		std::cout << std::hex << *it << std::endl;
	}
}

void CommandProcessor::print_top_changes() {
	std::map<CHANGES_COUNTER_T, MsgSequence*> sotred_sequence = m_sorter->sort_by_changes(ms_handler->msg_sequenses);
	for (auto it = sotred_sequence.rbegin(); it != sotred_sequence.rend(); it++) {
		std::cout << std::hex << it->second->msg_id << '\t' << std::dec << it->first << std::endl;
	}
}

void CommandProcessor::print_byte_data(std::unordered_map<std::string, std::string> input) {
	MSG_ID_T msg_id = std::stoi(input["id"], nullptr, 16);
	uint8_t byte_number = std::stoi(input["b"]);
	std::vector<std::pair<MSG_TIME_T, MSG_BYTE_T> > byte_data_seq = ms_handler->get_byte_sequence(msg_id, byte_number);
	std::vector<change_point> byte_changes_seq = ms_handler->get_changes_sequence(msg_id, byte_number);
	for (auto it = byte_data_seq.begin(); it != byte_data_seq.end(); it++) {
		std::cout << (int)it->first;
		std::cout << '\t';
		std::cout << (int)it->second << std::endl;
	}

	std::cout << std::endl;

	for (auto it = byte_changes_seq.begin(); it != byte_changes_seq.end(); it++) {
		std::cout << (int)it->time;
		std::cout << '\t';
		std::cout << (int)it->b_data;
		std::cout << '\t';
		std::cout << (int)it->edge;
		std::cout << std::endl;
	}
}

void CommandProcessor::print_pulse_near_mark(uint32_t mark_number) {

}