#include "UserInputHandler.h"
#include <iostream>
#include <string>

std::string UserInputHandler::get_file_name() {
	std::cout << "Enter file name > ";
	std::string result;
	std::getline(std::cin, result);
	return result;
}

std::string UserInputHandler::get_user_command() {
	std::cout << "> ";
	std::string result;
	std::getline(std::cin, result);
	return result;
}