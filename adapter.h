#pragma once
#include "maze2d.h"
#include "CommonSearcher.h"
#include <string>

class adapter
{
private:

public:
    CommonSearcher<std::string>& MazeToSearcher(Maze2d& m) {};

};

