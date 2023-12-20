#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <cstdlib>

class Game{

    public:
        Game(std::string fileName, int fileLines);
        virtual ~Game() = default;

        std::string genWord(std::string fileName);

    private:
        int triesLeft;
        int fileLines;
        constexpr static int maxTries{6};
        std::string word; 

        std::fstream& gotoLine(std::fstream& file, unsigned int num);
};

#endif