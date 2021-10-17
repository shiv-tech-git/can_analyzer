#pragma once
#include "MsgSequenceHandler.h"
#include "DataFormatter.h"
#include "MsgSorter.h"
#include "MsgFilter.h"

class CommandProcessor {
public:
	CommandProcessor(RawMsgSequenceHandler* msh);
	~CommandProcessor();
	void print_msg_ids();
	void print_top_changes();
	void print_byte_data(std::unordered_map<std::string, std::string> prc_input);
	void print_ids_with_pulse_near_mark(uint32_t mark_number);
	void print_ids_with_leading_edge_near_mark(uint32_t mark_number);
	void print_ids_with_falling_edge_near_mark(uint32_t mark_number);
	void print_ids_with_pulse_near_marks(uint32_t mark1, uint32_t mark2);

private:
	RawMsgSequenceHandler* ms_handler;
	DataFormatter* d_formatter;
	MsgSorter* m_sorter;
	MsgFilter* m_filter;

};