#include "CSVreader.h"
#include <fstream>
#include <sstream>

std::vector<std::string> readCSV(const std::string &filename)
{
    std::vector<std::string> data;
    std::ifstream file(filename);

    if (!file.is_open())
    {
        throw std::runtime_error("Could not open file: " + filename);
    }

    std::string line;

    while (std::getline(file, line))
    {
        data.push_back(line);
    }

    file.close();
    data.erase(data.begin());