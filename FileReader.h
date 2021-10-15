#pragma once
#include <vector>
#include <string>
#include "DataStructures.h"

class FileReader {
public:
	std::vector<msg_data> get_can_msgs_from_file_by_file_name(std::string filename);

private:
    uint32_t get_time(std::vector<char>& msg);
    uint32_t get_id(std::vector<char>& msg);
    std::vector<uint8_t> get_data(std::vector<char>& msg);
    uint8_t get_data_size(std::vector<char>& msg);
    uint8_t get_can_number(std::vector<char>& msg);
    std::vector<char> get_next_can_message(std::vector<unsigned char>::iterator& it);
    std::vector<msg_data> get_formatted_msg_data(std::vector<std::vector<char>> file_data);
    std::vector<std::vector<char>> get_file_data_as_vector(std::vector<unsigned char> buffer);
};