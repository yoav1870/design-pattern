#include "command.h"

void compress::execute(const std::string& param) {
    std::string name_maze, file_name;
    int pos = 0;
    pos = param.find(" ");
    name_maze = param.substr(0, pos);
    file_name = param.substr(pos + 1);
    if (myModel::getInstance().getMaze(name_maze))
    {
        MazeCompression::compressFile(myModel::getInstance().getCurMaze(), file_name);
    }
    else
        myController::getInstance().getOutStream() << "Maze doesn't exist" << std::endl;

};

void dir::execute(const std::string& param) {
     try {
         for (const auto& entry : std::filesystem::directory_iterator(param)) {
             myController::getInstance().getOutStream() << entry.path().filename().string() << '\n';
         }
     }
     catch (std::filesystem::filesystem_error& e) {
         std::cerr << "Error accessing path: " << e.what() << '\n';
     }
};

void display::execute(const std::string& param) {
    if (myModel::getInstance().getMaze(param))
    {
        myModel::getInstance().getCurMaze().displayMaze();
    }
    else
        myController::getInstance().getOutStream() << "Maze doesn't exist" << std::endl;
};

void display_solution::execute(const std::string& param) {
    Solution<Maze2d> s;
    s.getSolution();
};


void Exit::execute(const std::string& param) {
    myView::getInstance().setShouldExit(true);
};

void file_size::execute(const std::string& param) {
    myController::getInstance().getOutStream() << "File size: " << File::getFileSize(param) << " byte" << std::endl;

};

void generate_maze::execute(const std::string& param) {
    myController::getInstance().getOutStream() << "generate maze:" << param << std::endl;
    int rows, cols;
    do {
        myController::getInstance().getOutStream() << "Enter the number of rows (greater than 1): ";
        myController::getInstance().getInStream() >> rows;
        if (rows <= 1) {
            myController::getInstance().getOutStream() << "Rows should be greater than 1." << std::endl;
        }
    } while (rows <= 1);

    do {
        myController::getInstance().getOutStream() << "Enter the number of columns (greater than 1): ";
        myController::getInstance().getInStream() >> cols;
        if (cols <= 1) {
            myController::getInstance().getOutStream() << "Columns should be greater than 1." << std::endl;
        }
    } while (cols <= 1);

    myModel::getInstance().getCurMaze() = Maze2d(rows * 2 + 1, cols * 2 + 1, param);
    myModel::getInstance().getCurMaze().generate();
    myModel::getInstance().addMaze(myModel::getInstance().getCurMaze().getName(), myModel::getInstance().getCurMaze());
    myModel::getInstance().notify();
}

void load_compress::execute(const std::string& param) {
    std::string name_maze, file_name;
    int pos = 0;
    pos = param.find(" ");
    name_maze = param.substr(0, pos);
    file_name = param.substr(pos + 1);
    MazeCompression::loadCompress(file_name, name_maze);
};

void load_maze::execute(const std::string& param) {
    std::string name_maze, file_name;
    int pos = 0;
    pos = param.find(" ");
    file_name = param.substr(0, pos);
    name_maze = param.substr(pos + 1);
    File::importFromFile(file_name, name_maze);
};


void maze_size::execute(const std::string& param) {
    if (myModel::getInstance().getMaze(param))
    {
        myController::getInstance().getOutStream() << "Maze size:" << myModel::getInstance().getCurMaze().getMazeSize() << " byte" << std::endl;
    }
    else
        myController::getInstance().getOutStream() << "Maze doesn't exist" << std::endl;
};


void save_maze::execute(const std::string& param) {
    std::string name_maze, file_name;
    int pos = 0;
    pos = param.find(" ");
    name_maze = param.substr(0, pos);
    file_name = param.substr(pos + 1);
    if (myModel::getInstance().getMaze(name_maze))
    {
        File::exportToFile(myModel::getInstance().getCurMaze(), file_name);
    }
    else
        myController::getInstance().getOutStream() << "Maze doesn't exist" << std::endl;
};

void solve::execute(const std::string& param) {
    std::string name_maze, algo;
    int pos = 0;
    pos = param.find(" ");
    name_maze = param.substr(0, pos);
    algo = param.substr(pos + 1);
    if (myModel::getInstance().getMaze(name_maze))
    {
        if (algo.compare("bfs") == 0)
        {
            BFS<Maze2d> b;
            b.search();
        }
        else if (algo.compare("astar") == 0)
        {
            AStar<Maze2d> a;
            a.search();
        }
        else
            myController::getInstance().getOutStream() << "the input is incorrect" << std::endl;
    }
    else
        myController::getInstance().getOutStream() << "Maze doesn't exist" << std::endl;
};







