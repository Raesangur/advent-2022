#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
    std::vector<int> elvesCalories{1};

    std::ifstream file{"input.txt"};
    if(!file.is_open())
        return -1;

    std::string line;
    while(std::getline(file, line))
    {
        if (line == "")
        {
            elvesCalories.emplace_back(0);
        }
        else
            elvesCalories.back() += std::stoi(line);
    }

    //int max = *std::max_element(elvesCalories.begin(), elvesCalories.end());
    std::sort(elvesCalories.begin(), elvesCalories.end());
    auto it = elvesCalories.end() - 1;
    std::cout << *it + *(it - 1) + *(it - 2) << std::endl;
}
