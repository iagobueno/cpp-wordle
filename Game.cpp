#include "Game.hpp"

#include <fstream>
#include <limits>
#include <iostream>

Game::Game(std::string fileName, int fileLines)
    :triesLeft{this->maxTries}, fileLines{fileLines} {
        this->word = genWord(fileName);
}

// goes to a specific line at a file
std::fstream& Game::gotoLine(std::fstream& file, unsigned int num){
    file.seekg(std::ios::beg);
    for(unsigned int i = 0; i < num - 1; ++i){
        file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    return file;
}

std::string Game::genWord(std::string fileName){
    // generates a random value
    srand((unsigned) time(NULL));
    int r = 1 + (rand() % this->fileLines);

    std::fstream file(fileName);
    gotoLine(file, r);

    std::string line;
    file >> line;

    std::cout << line << std::endl;

    return line;
}