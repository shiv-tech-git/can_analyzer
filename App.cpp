#include <string>
#include "App.h"
#include "UserInputHandler.h"
#include "FileReader.h"
#include "Core.h"

#include <windows.h>

void App::start() {

	_COORD coordinates;
	coordinates.X = 1000;
	coordinates.Y = 4000;

	SetConsoleScreenBufferSize(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coordinates
	);

	UserInputHandler uih;
	//std::string file_name = uih.get_file_name();
	std::string file_name = "in.bin";
	FileReader fr;
	std::vector<msg_data> msgs = fr.get_can_msgs_from_file_by_file_name(file_name);
	Core core(msgs);
	std::string cmd = "";

	while (1) {
		cmd = uih.get_user_command();
		if (cmd == EXIT_CMD) {
			return;
		}

		core.handle_user_command(cmd);
	}
}