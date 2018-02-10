#include <iostream>
#include <string>
#include <vector>
#include <sstream>

//
// Splits strings into words, seperate at each space character.
// 
void SplitString(std::string& str, std::vector<std::string>& res)
{
    std::stringstream ss(str);
    std::string item;
    while (std::getline(ss, item, ' '))
    {
        res.push_back(item);
    }
}

int main()
{
    int numOfTestCases = 0;
    std::string animalSounds = "";
    std::string preRecorded = ""; // i.e. dog goes woof
    std::string testRecorded = "";
    std::vector<std::string> knownSounds;
    std::vector<std::string> testCaseSounds;

    std::cin >> numOfTestCases;
    std::cin.ignore();

    for (int i = 0; i < numOfTestCases; i++)
    {
        std::getline(std::cin, animalSounds);

        SplitString(animalSounds, knownSounds); // 
        while (testRecorded != "what does the fox say?")
        {
            testRecorded.clear();
            std::getline(std::cin, testRecorded);

            if (testRecorded == "what does the fox say?") break;

            SplitString(testRecorded, testCaseSounds);
            for (unsigned int j = 0; j < knownSounds.size(); j++)
            {
                if (knownSounds[j] == testCaseSounds[2]) {
                    knownSounds.erase(knownSounds.begin() + j--);
                }
            }
            testCaseSounds.clear();
        }
        
        for (unsigned int i = 0; i < knownSounds.size(); i++)
        {
            std::cout << knownSounds[i] << " ";
        }

        std::cout << "\n";
        knownSounds.clear();
        testRecorded.clear();
    }

    return 0;
}