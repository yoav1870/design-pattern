#pragma once


#include <iostream>
#include <memory>
#include "myController.h"
#include "subscriber.h"
class myView : public subscriber{
private:
    static std::unique_ptr<myView> instance;
    static bool shouldExit;
    myView() {}; 

public:
    myView(const myView&) = delete; 
    myView& operator=(const myView&) = delete; 

    static myView& getInstance() {
        if (!instance) {
            instance = std::unique_ptr<myView>(new myView());
        }
        return *instance;
    }

    void start();
    void setShouldExit(bool exit) { shouldExit = exit; };
    bool getShouldExit() { return shouldExit; };
    void update();
};
