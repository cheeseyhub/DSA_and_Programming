// FREEZE CODE BEGIN
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "CSVreader.h"

std::vector<std::string> split(const std::string &str, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(str);
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}
void sort(std::vector<std::string> &data)
{
    for (int i = 1; i < data.size(); i++)
    {
        std::string currentRow = data[i];
        // getting the current row and splitting it
        std::vector<std::string> currentAccount = split(data[i], ',');
        // getting the current account money
        int currentAccountNumber = std::stoi(currentAccount[0]);

        // insertion sort pointer
        int placeToInsert = i - 1;

        // Getting the previous row and its  money
        std::vector<std::string> placeToInsertAccount = split(data[placeToInsert], ',');
        int placeToInsertAccountNumber = std::stoi(placeToInsertAccount[0]);

        while (placeToInsert >= 0 && currentAccountNumber < placeToInsertAccountNumber)
        {
            data[placeToInsert + 1] = data[placeToInsert];
            placeToInsert--;
            if (placeToInsert >= 0)
            {
                placeToInsertAccount = split(data[placeToInsert], ',');
                placeToInsertAccountNumber = std::stoi(placeToInsertAccount[0]);
            }
        }

        data[placeToInsert + 1] = currentRow;
    }
}

int main(int argc, char *argv[])
{
    std::string path = argv[1];
    std::vector<std::string> data = readCSV(path);

    sort(data);

    // Print the first and last elements after sorting
    std::cout << data.front() << std::endl;
    std::cout << data.back() << std::endl;

    return 0;
}
