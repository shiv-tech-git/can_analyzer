#include "Core.h"
#include "RawMsgSequenceHandler.h"
#include <iostream>

Core::Core(std::vector<msg_data> msgs) {
	RawMsgSequenceHandler* rmsh = new RawMsgSequenceHandler();
	rmsh->init_with_msg_data(msgs);
	ms_handler = rmsh;
	c_proc = new CommandProcessor(ms_handler);
}

Core::~Core() {
	delete c_proc;
	delete ms_handler;
}

std::unordered_map<std::string, std::string> Core::parse_user_input(std::string input) {
	std::unordered_map<std::string, std::string> result;

	std::string delimiter = " ";

	size_t pos = 0;
	std::string token, key, value;

	while (input.size() > 0) {
		pos = input.find(delimiter);
		if ((pos = input.find(delimiter)) == std::string::npos) {
			pos = input.size();
		}
		token = input.substr(0, pos);
		input.erase(0, pos + delimiter.length());

		if (result.size() == 0) {
			result.insert(std::pair<std::string, std::string>("cmd", token));
		}
		else {
			pos = token.find("=");
			key = token.substr(0, pos);
			value = token.substr(pos + 1, token.length());
			result.insert(std::pair<std::string, std::string>(key, value));
		}
	}
	return result;
}

void Core::handle_user_command(std::string input) {
	if (input == "") return;

	std::unordered_map<std::string, std::string> prc_input = parse_user_input(input);
	std::string cmd = prc_input["cmd"];

	if (cmd == PRINT_RESULT_CMD) {
		std::cout << "pring raw data" << std::endl;
	}
	else if (cmd == PRINT_IDS_CMD) {
		c_proc->print_msg_ids();
	}
	else if (cmd == PRINT_TOP_CHANGES) {
		c_proc->print_top_changes();
	}
	else if (cmd == GET_BYTE_DATA) {
		c_proc->print_byte_data(prc_input);
	}
	else if (cmd == FILTER_MSG) {
		std::string mode = prc_input["mode"];
		if (mode == "p") {
			uint32_t mark = stoi(prc_input["m"]);
			c_proc->print_ids_with_pulse_near_mark(mark);
		}
		else if (mode == "le") {
			uint32_t mark = stoi(prc_input["m"]);
			c_proc->print_ids_with_leading_edge_near_mark(mark);
		}
		else if (mode == "fe") {
			uint32_t mark = stoi(prc_input["m"]);
			c_proc->print_ids_with_falling_edge_near_mark(mark);
		}
		else if (mode == "p2") {
			uint32_t mark1 = stoi(prc_input["m1"]);
			uint32_t mark2 = stoi(prc_input["m2"]);
			c_proc->print_ids_with_pulse_near_marks(mark1, mark2);
		}
	}
}

