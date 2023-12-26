#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "myModel.h"

class File
{
public:
    static bool exportToFile(Maze2d& m, const std::string& fileName);
    static bool importFromFile( const std::string& fileName, std::string& name);
    static std::size_t getFileSize(const std::string& fileName);

};
