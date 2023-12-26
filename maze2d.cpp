#include "maze2d.h"




bool Maze2d::isValidCell(int x, int y, int maze_rows) {
    return x >= 0 && x < maze_rows && y >= 0 && y < mazeCols;
}

bool Maze2d::isWall(const std::vector<std::vector<char>>& visited, int x, int y) {
    return maze[x][y] == WALL;
}

bool Maze2d::isVisited(const std::vector<std::vector<char>>& visited, int x, int y) {
    return visited[x][y] != WALL;
}

bool Maze2d::isUnvisited(const std::vector<std::vector<char>>& visited, int x, int y) {
    return visited[x][y] == WALL;
}

bool Maze2d::isPath(int x, int y) {
    return maze[x][y] == PATH;
}

bool Maze2d::isDeadEnd(const std::vector<std::vector<char>>& visited, int x, int y) {
    int numWalls = 0;
    if (isValidCell(x - 1, y, visited.size()) && isWall(visited, x - 1, y)) numWalls++;
    if (isValidCell(x + 1, y, visited.size()) && isWall(visited, x + 1, y)) numWalls++;
    if (isValidCell(x, y - 1, visited.size()) && isWall(visited, x, y - 1)) numWalls++;
    if (isValidCell(x, y + 1, visited.size()) && isWall(visited, x, y + 1)) numWalls++;
    return numWalls >= 3;
}

Direction Maze2d::getRandomDirection(std::mt19937& rng) {
    std::uniform_int_distribution<int> dist(0, 3);
    return static_cast<Direction>(dist(rng));
}

void Maze2d::initial_start_end() {
    int startRow = 1, startCol = 1;
    int endRow = mazeRows - 2, endCol =  mazeCols - 2;
    maze[startRow][startCol] = START;
    maze[endRow][endCol] = END;

    return;
}


bool Maze2d::generate() {
    std::vector<std::vector<char>> visited(mazeRows, std::vector<char>(mazeCols, WALL));
    std::stack<std::pair<int, int>> cellStack;
    std::vector<Direction> directions = { Direction::NORTH, Direction::EAST, Direction::SOUTH, Direction::WEST };
    std::random_device rd;
    std::mt19937 rng(rd());
    auto start = std::chrono::high_resolution_clock::now();

    int startX = 1, startY = 1;
    maze[startX][startY] = PATH;
    visited[startX][startY] = PATH;
    cellStack.push(std::make_pair(startX, startY));

    while (!cellStack.empty()) {
        int x = cellStack.top().first;
        int y = cellStack.top().second;
        bool cellVisited = false;

        std::shuffle(directions.begin(), directions.end(), rng);

        for (const auto& direction : directions) {
            int newX = x, newY = y;
            switch (direction) {
            case Direction::NORTH:
                newX -= 2;
                break;
            case Direction::EAST:
                newY += 2;
                break;
            case Direction::SOUTH:
                newX += 2;
                break;
            case Direction::WEST:
                newY -= 2;
                break;
            }

            if (isValidCell(newX, newY, mazeRows) && isUnvisited(visited, newX, newY)) {
                maze[newX][newY] = PATH;                        // make the first path
                maze[(newX + x) / 2][(newY + y) / 2] = PATH;    // make the middle path to the cell we got
                visited[newX][newY] = PATH;                     // update the visited 
                cellStack.push(std::make_pair(newX, newY));     // update the cellstack with the new pair 
                cellVisited = true;                             // gilgol 
                break;
            }
        }

        if (!cellVisited) {
            cellStack.pop();
        }
    }
    
    initial_start_end();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "Time taken by generateMaze: " << duration << " milliseconds" << std::endl;
    return true;
}



void Maze2d::displayMaze() {
    std::cout << "Here's the maze you asked for. Enjoy! :D" << std::endl;
    for (const auto& row : maze) {
        for (char cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}

std::size_t Maze2d::getMazeSize() {
    std::size_t totalSize = 0;

    for (const auto& row : maze) {
        totalSize += row.size(); // Count characters in each row
    }

    return totalSize * sizeof(char); 
}
