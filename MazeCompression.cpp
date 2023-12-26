#include "MazeCompression.h"



bool MazeCompression :: compressFile(Maze2d& m, const std::string& fileName)
{
    std::ofstream file;
    file.open(fileName, std::ios::app);

    if (!file) {
        std::cerr << "Unable to open file " << fileName << std::endl;
        return false;
    }
    file << m.getRows() << 'X' << m.getCols() << std::endl;
    for (const auto& row : m.getMaze()) {
        int countWall = 0;
        int countPath = 0;
        for (char cell : row) {
            if (cell == WALL) {
                countWall++;
            }
            else {
                if (countWall > 0) {
                    file << WALL << countWall << ",";
                    countWall = 0;
                }
                
            }
            if (cell == PATH)
            {
                countPath++;
            }
            else {
                if (countPath > 0)
                {
                    file << "_" << countPath << ",";
                    countPath = 0;
                }
                
            }
            if (cell == START)
            {
                file << "S" << ",";
            }
            if (cell == END)
            {
                file << "E" << ",";
            }
           
        }

        if (countWall > 0) {
            file << WALL << countWall << ",";
        }
        if (countPath > 0) {
            file << "_" << countPath << ",";
        }
        file << '\n';
    }

    file.close();
    std::cout << "Maze compress to " << fileName << std::endl;
    return true;

}


bool MazeCompression::loadCompress(const std::string& fileName, std::string& name) {
    std::ifstream file;
    file.open(fileName);

    if (!file) {
        std::cerr << "Unable to open file " << fileName << std::endl;
        return false;
    }

    std::string line;
    

    int rows, cols;
    char separator;
    file >> rows >> separator >> cols;
   

    file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    myModel::getInstance().getCurMaze() = Maze2d(rows, cols , name) ;


    int row = 0, col = 0;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string token;

        while (getline(iss, token, ',')) {
            if (token[0] == WALL) {
                int wallnumber = std::stoi(token.substr(1)); // Remove the '#'
                
                for (int i = 0; i < wallnumber; i++) {
                    myModel::getInstance().getCurMaze().getMaze()[row][col] = WALL;
                    col++;
                }
            }
            else if (token[0] == '_') {
                int pathnumber = std::stoi(token.substr(1)); // Remove the '_'
                for (int i = 0; i < pathnumber; i++) {
                    myModel::getInstance().getCurMaze().getMaze()[row][col] = PATH;
                    col++;
                }
            }
            else if (token[0] == 'S') {
                myModel::getInstance().getCurMaze().getMaze()[row][col] = START;
                col++;
            }
            else if (token[0] == 'E') {
                myModel::getInstance().getCurMaze().getMaze()[row][col] = END;
                col++;
            }
        }
        row++;
        col = 0;
    }

    file.close();
    
    myModel::getInstance().addMaze(name, myModel::getInstance().getCurMaze());
    std::cout << "Maze: " << name << " compress from " << fileName << std::endl;
    return true; 
}