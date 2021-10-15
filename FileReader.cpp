#include "FileReader.h"
#include <fstream>
#include <iterator>
#include <iostream>
#include "DataStructures.h"


uint32_t FileReader::get_time(std::vector<char>& msg) {
    return msg[12] + msg[13] * 256 + msg[14] * 256 * 256;
}

uint32_t FileReader::get_id(std::vector<char>& msg) {
    uint32_t id = (uint8_t)msg[2];
    id <<= 8;
    id |= (uint8_t)msg[3];
    int tmp = 0;
    for (int i = 0; i < 5; i++) {
        tmp = id & 1;
        id >>= 1;
        id |= (tmp << 15);
    }
    return id;
}

std::vector<uint8_t> FileReader::get_data(std::vector<char>& msg) {
    std::vector<uint8_t> result;
    result.reserve(8);
    int byte_number = 8;
    for (int i = 0; i < 8; i++) {
        if (byte_number == 12) byte_number = 4;
        result.push_back(msg[byte_number]);
        byte_number++;
    }

    return result;
}

uint8_t FileReader::get_data_size(std::vector<char>& msg) {
    return msg[15] >> 4;
}

uint8_t FileReader::get_can_number(std::vector<char>& msg) {
    return msg[15] &= 15;
}

std::vector<std::vector<char>> FileReader::get_file_data_as_vector(std::vector<unsigned char> buffer) {
    auto it = buffer.begin();
    std::vector<std::vector<char>> can_messages;
    can_messages.reserve(buffer.size() / 16);
    while (it != buffer.end()) {
        can_messages.push_back(get_next_can_message(it));
    }
    return can_messages;
}

std::vector<struct msg_data> FileReader::get_formatted_msg_data(std::vector<std::vector<char>> file_data) {
    std::vector<struct msg_data> result;
    result.reserve(file_data.size());
    for (auto it = file_data.begin(); it != file_data.end(); it++) {
        msg_data tmp = {
            get_id(*it),
            get_data(*it),
            get_time(*it),
            get_data_size(*it)
        };
        result.push_back(tmp);
    }
    return result;
}


std::vector<char> FileReader::get_next_can_message(std::vector<unsigned char>::iterator& it) {
    std::vector<char> result;
    for (int i = 0; i < 16; i++)
    {
        result.push_back(*it);
        it++;
    }
    return result;
}

std::vector<struct msg_data>  FileReader::get_can_msgs_from_file_by_file_name(std::string filename) {
    std::ifstream input(filename, std::ios::binary);
    std::vector<unsigned char> buffer(std::istreambuf_iterator<char>(input), {});
    std::vector<std::vector<char>> file_data = get_file_data_as_vector(buffer);
    return get_formatted_msg_data(file_data);

}