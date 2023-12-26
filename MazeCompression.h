#pragma once


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "myModel.h"


class MazeCompression {

public:
	static bool compressFile(Maze2d& m, const std::string& fileName);
	static bool loadCompress(const std::string& fileName, std::string& name);
	virtual ~MazeCompression() = 0;
};