#pragma once
#include "MsgSequenceHandler.h"
#include "DataFormatter.h"
#include "MsgSorter.h"

class CommandProcessor {
public:
	CommandProcessor(MsgSequenceHandler* msh);
	~CommandProcessor();
	void print_msg_ids();
	void print_top_changes();

private:
	MsgSequenceHandler* ms_handler;
	DataFormatter* d_formatter;
	MsgSorter* m_sorter;

};