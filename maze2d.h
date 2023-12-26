#pragma once

#include <vector>
#include <stack>
#include <random>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <string>
#include "Maze2dGenerator.h"

const char WALL = '#';
const char PATH = ' ';
const char START = 'S';
const char END = 'E';


enum class Direction { NORTH, EAST, SOUTH, WEST };
 
class Maze2d : public Maze2dGenerator{
    private:
        static int mazeNum;
        std::string mazeName;
        std::vector<std::vector<char>> maze;
        int mazeRows;
        int mazeCols;

        bool isValidCell(int x, int y, int mazeRows);
        bool isVisited(const std::vector<std::vector<char>>& visited, int x, int y);
        bool isUnvisited(const std::vector<std::vector<char>>& visited, int x, int y);
        bool isWall(const std::vector<std::vector<char>>& visited, int x, int y);
        bool isPath(int x, int y);
        bool isDeadEnd(const std::vector<std::vector<char>>& visited, int x, int y);
        Direction getRandomDirection(std::mt19937& rng);
        void initial_start_end();
    public:
        std::size_t getMazeSize();
        Maze2d(int rows, int cols, std::string name) : mazeRows(rows), mazeCols(cols), maze(rows, std::vector<char>(cols, WALL)), mazeName(name) {};
        Maze2d(){};
        bool generate();
        void displayMaze();
        std::vector<std::vector<char>>& getMaze(){return maze;};
        std::string getName(){return mazeName;};
        int getRows(){return mazeRows;};
        int getCols(){return mazeCols;};
        void setName(std::string name) { mazeName = name; };
        void setRows(int row) { mazeRows = row; };
        void setCols(int col) { mazeCols = col; };
 
};

