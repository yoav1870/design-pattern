#include "File.h"

bool File::exportToFile(Maze2d& m, const std::string& fileName) {
    std::ofstream file;
    file.open(fileName, std::ios::app);

    if (!file) {
        std::cerr << "Unable to open file " << fileName << std::endl;
        return false;
    }

    file << m.getName() << std::endl;
    file << m.getRows()  << 'X' << m.getCols()  << std::endl;
    for (const auto& row : m.getMaze()) {
        for (char cell : row) {
            file << cell << " ";
        }
        file << '\n';
    }
    file.close();
    std::cout << "Maze exported to " << fileName << std::endl;
    return true;
}
bool File::importFromFile(const std::string& fileName, std::string& name) {
    std::ifstream file;
    file.open(fileName);

    if (!file) {
        std::cerr << "Unable to open file " << fileName << std::endl;
        return false;
    }

    std::string buff, line;
    std::getline(file, buff);


    int rows, cols;
    char separator;
    file >> rows >> separator >> cols;


    file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    myModel::getInstance().getCurMaze() = Maze2d(rows, cols, name);
    int row = 0, col = 0;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        for (int i = 0; i < cols * 2; i = i + 2)
        {
            myModel::getInstance().getCurMaze().getMaze()[row][col] = line[i];
            col++;
        }
        row++;
        col = 0;
    }
    file.close();
    std::cout << "Maze imported from " << fileName << std::endl;
    if (!myModel::getInstance().getMaze(name))
    {
        myModel::getInstance().addMaze(name, myModel::getInstance().getCurMaze());
    }
    else
        std::cout << "Name of maze exist allready" << std::endl;
    
    return true;
}



std::size_t File::getFileSize(const std::string& fileName)
{
     struct stat fileStat;
     if (stat(fileName.c_str(), &fileStat) == 0) {
         return static_cast<std::size_t>(fileStat.st_size);
     }
    return 0; // Return 0 if there's an error
}