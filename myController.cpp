#include "myController.h"
#include "command.h"

std::unique_ptr<myController> myController::instance = nullptr;

void myController::initializeCommands() {
    
    commands["dir"] = new dir();
    commands["generate_maze"] = new generate_maze();
    commands["display"] = new display();
    commands["save_maze"] = new save_maze();
    commands["load_maze"] = new load_maze();
    commands["maze_size"] = new maze_size();
    commands["file_size"] = new file_size();
    commands["compress"] = new compress();
    commands["load_compress"] = new load_compress();
    commands["solve"] = new solve();
    commands["display_solution"] = new display_solution();
    commands["exit"] = new Exit();
}

void myController::processCommand() {
    std::string input;
    getline(*inStream, input);
    if (input.empty()) {
        return; // Exit the function
    }
    size_t spacePos = input.find(' ');

    std::string command;
    std::string params;

    if (spacePos != std::string::npos) {
        command = input.substr(0, spacePos);
        params = input.substr(spacePos + 1);
    }
    else {
        command = input;
    }

    auto commandIt = commands.find(command);
    if (commandIt != commands.end()) {
        commandIt->second->execute(params);
    }
    else {
        *outStream << "Unknown command: " << command << std::endl;
    }
}




