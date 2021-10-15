#include <iostream>

#include "CommandProcessor.h"
#include "MsgSorter.h"

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