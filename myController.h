#pragma once

#include <memory>
#include <iostream>
#include <string>
#include <functional>
#include <map>
#include <filesystem>
#include "Solution.h"
#include "BFS.h"
#include "AStar.h"
#include "File.h"
#include "MazeCompression.h" 
#include "myView.h"




class command; 


class myController 
{
private:
    static std::unique_ptr<myController> instance;
    myController() : inStream(&std::cin), outStream(&std::cout) {}
    std::map<std::string, command*> commands;
    std::istream* inStream;
    std::ostream* outStream;


public:
    myController(const myController&) = delete;
    myController& operator=(const myController&) = delete;

    static myController& getInstance() {
        if (!instance) {
            instance = std::unique_ptr<myController>(new myController());
        }
        return *instance;
    }

    ~myController(){
        for (auto& pair : commands) {
            delete pair.second;
        }
    };
    void initializeCommands();
    void processCommand();
    void setStreams(std::istream& in, std::ostream& out) {
        inStream = &in;
        outStream = &out;
    }
    std::ostream& getOutStream() { return *outStream; };
    std::istream& getInStream() { return *inStream; };
};
