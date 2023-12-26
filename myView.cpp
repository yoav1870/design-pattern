#include "myView.h"

std::unique_ptr<myView> myView::instance = nullptr;
bool myView::shouldExit = false;

void myView::start() {
    myController::getInstance().setStreams(std::cin, std::cout);
    myController::getInstance().initializeCommands();
    myController::getInstance().getOutStream() << "welcome to our maze builder please enter command" << std::endl;
    while (!shouldExit) {
        
        myController::getInstance().processCommand();
    }
}

void myView::update(){
    myController::getInstance().getOutStream() << "Maze created successfully" << std::endl;
}