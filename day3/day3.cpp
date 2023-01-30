#include <algorithm>
#include <iostream>
#include <fstream>
#include <map>
#include <string>

#define PART_TWO

int find_duplicates(const std::string_view c1, const std::string_view c2)
{
    for(char i : c1)
    {
        for(char j : c2)
        {
            if (i == j)
            {
                int num = (i <= 'Z' ? i - 'A' + 26 : i - 'a') + 1;
                std::cout << num << std::endl;
                return num;
            }
        }
    }
    return 0;
}

int find_duplicates(const std::string_view c1, const std::string_view c2, const std::string_view c3)
{
    for(char i : c1)
    {
        for(char j : c2)
        {
            for (char k : c3)
                if (i == j && i == k)
                {
                    int num = (i <= 'Z' ? i - 'A' + 26 : i - 'a') + 1;
                    std::cout << num << std::endl;
                    return num;
                }
        }
    }
    return 0;
}

int main()
{
    int total = 0;

    std::ifstream file{"input.txt"};
    if(!file.is_open())
        return -1;

    std::array<std::string, 3> groupSacks;
    int i = 0;
    std::string line;
    while(std::getline(file, line))
    {
#ifndef PART_TWO
        std::string c1 = line.substr(0, line.size() / 2);
        std::string c2 = line.substr(line.size() / 2, line.size());

        total += find_duplicates(c1, c2);
#else
        groupSacks[i++] = line;
        if (i == 3)
        {
            i = 0;
            total += find_duplicates(groupSacks[0], groupSacks[1], groupSacks[2]);
        }
#endif        
    }

    std::cout << total << std::endl;
}
