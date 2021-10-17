#pragma once
#include <vector>
#include <string>
#include <unordered_map>

#include "DataStructures.h"
#include "RawMsgSequenceHandler.h"
#include "CommandProcessor.h"

#define EXIT_CMD "exit"
#define PRINT_RESULT_CMD "result"
#define PRINT_IDS_CMD "print_ids"
#define PRINT_TOP_CHANGES "print_top_changes"
#define GET_BYTE_DATA "get_byte_data"
#define FILTER_MSG "filter_msg"


class Core {
public:
	Core(std::vector<msg_data> msgs);
	~Core();
	void handle_user_command(std::string cmd);

private:
	CommandProcessor* c_proc;
	RawMsgSequenceHandler* ms_handler;
	std::unordered_map<std::string, std::string> parse_user_input(std::string input);

};