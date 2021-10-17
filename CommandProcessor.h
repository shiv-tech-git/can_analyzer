#pragma once
#include "MsgSequenceHandler.h"
#include "DataFormatter.h"
#include "MsgSorter.h"
#include "MsgFilter.h"

class CommandProcessor {
public:
	CommandProcessor(MsgSequenceHandler* msh);
	~CommandProcessor();
	void print_msg_ids();
	void print_top_changes();
	void print_byte_data(std::unordered_map<std::string, std::string> prc_input);
	void print_pulse_near_mark(uint32_t mark_number);

private:
	MsgSequenceHandler* ms_handler;
	DataFormatter* d_formatter;
	MsgSorter* m_sorter;
	MsgFilter* m_filter;

};