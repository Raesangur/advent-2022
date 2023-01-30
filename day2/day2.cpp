#include <iostream>
#include <fstream>
#include <map>
#include <string>

constexpr int rockPoint    = 1;
constexpr int papePoint   = 2;
constexpr int scisPoint = 3;
constexpr int tiePoint = 3;
constexpr int winPoint = 6;
constexpr int losPoint = 0;


const std::map<std::string, int> pointsForPlay1
{
    {"A X", tiePoint + rockPoint},     // Rock - Rock     : Tie
    {"A Y", winPoint + papePoint},     // Rock - Paper    : Win
    {"A Z", losPoint + scisPoint},     // Rock - Scissors : Lose
    {"B X", losPoint + rockPoint},     // Paper - Rock     : Lose
    {"B Y", tiePoint + papePoint},     // Paper - Paper    : Tie
    {"B Z", winPoint + scisPoint},     // Paper - Scissors : Win
    {"C X", winPoint + rockPoint},     // Scissors - Rock     : Win
    {"C Y", losPoint + papePoint},     // Scissors - Paper    : Lose
    {"C Z", tiePoint + scisPoint},     // Scissors - Scissors : Tie
};

const std::map<std::string, int> pointsForPlay2
{
    {"A Z", winPoint + papePoint},     // Rock - Paper
    {"A Y", tiePoint + rockPoint},     // Rock - Rock
    {"A X", losPoint + scisPoint},     // Rock - Scissors
    {"B Z", winPoint + scisPoint},     // Paper - Scissors
    {"B Y", tiePoint + papePoint},     // Paper - Paper
    {"B X", losPoint + rockPoint},     // Paper - Rock
    {"C Z", winPoint + rockPoint},     // Scissors - Rock
    {"C Y", tiePoint + scisPoint},     // Scissors - Scissors
    {"C X", losPoint + papePoint},     // Scissors - Paper
};

int main()
{
    int total = 0;

    std::ifstream file{"input.txt"};
    if(!file.is_open())
        return -1;

    std::string line;
    while(std::getline(file, line))
    {
        total += pointsForPlay2.find(line)->second;
    }

    std::cout << total << std::endl;
}
