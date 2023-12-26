#include "myModel.h"

std::unique_ptr<myModel> myModel::instance = nullptr;

bool myModel::addMaze(const std::string& mazeName, const Maze2d& maze) {
    auto result = mazes.insert({ mazeName, maze });
    return result.second; // Returns true if insertion was successful (mazeName didn't exist)
}

bool myModel::getMaze(const std::string& mazeName) {
    auto it = mazes.find(mazeName);
    if (it != mazes.end()) {
        curMaze = it->second;
        return true;
    }
    return false; // Maze with mazeName not found
}

bool myModel::removeMaze(const std::string& mazeName) {
    return mazes.erase(mazeName) > 0;
}

void myModel::clearAllMazes() {
    mazes.clear();
}

void myModel::initializeSubscribers(){
    subscribe(&myView::getInstance());
}
