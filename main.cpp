#include <fstream>
#include <iostream>
#include <limits>

#include "Game.hpp"
#include "UserInterface.hpp"

int main() {
    Game *game{new Game{"./dict/br-utf8-5.txt", 5905}};
    UserInterface *ui{new UserInterface{}};

    ui->printScreen();

    return 0;
}