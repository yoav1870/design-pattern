#pragma once


#include <unordered_map>
#include <string>
#include <memory>
#include "maze2d.h"
#include "publisher.h"
#include "myView.h"
class myModel : public publisher {
private:
    std::unordered_map<std::string, Maze2d> mazes;
    Maze2d curMaze;
    static std::unique_ptr<myModel> instance;
    myModel() { initializeSubscribers(); };
    void clearAllMazes();

public:
    myModel(const myModel&) = delete;
    myModel& operator=(const myModel&) = delete;

    static myModel& getInstance() {
        if (!instance) {
            instance = std::unique_ptr<myModel>(new myModel());
            
        }
        return *instance;
    }

    bool addMaze(const std::string& mazeName, const Maze2d& maze);
    bool getMaze(const std::string& mazeName);
    bool removeMaze(const std::string& mazeName);
    void initializeSubscribers();
    Maze2d& getCurMaze() { return curMaze; };
    ~myModel() {};
    
};
