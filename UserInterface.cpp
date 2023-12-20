#include "UserInterface.hpp"

#include <sys/ioctl.h>

#include <iostream>

const std::string UserInterface::white = "\033[1;37m";
const std::string UserInterface::lightGray = "\033[38:5:8m";
const std::string UserInterface::green = "\033[1;32m";
const std::string UserInterface::yellow = "\033[1;33m";

UserInterface::UserInterface()
    : state{0},
      menuState{0},
      boxEmpty{"│                         │"},
      boxLid{"┌─────────────────────────┐"},
      boxBottom{"└─────────────────────────┘"} {
    // get window size
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    this->winWidth = w.ws_col;
    this->winHeight = w.ws_row;

    // calculate left padding
    this->leftPadding = (winWidth / 2) - (this->boxWidth / 2);

    this->menuString = {
        "                         ", "                         ",
        "         P L A Y         ", "     S E T T I N G S     ",
        "   S T A T I S T I C S   ", "         Q U I T         ",
        "                         ", "                         ",
    };
}

void UserInterface::printLeftPadding() {
    for (int i = 0; i < this->leftPadding; ++i) std::cout << ' ';
}

void UserInterface::printEndLine(int l) {
    for (int i = 0; i < l; ++i) std::cout << std::endl;
}

void UserInterface::printMenu() {
    int verticalPadding{(this->winHeight - this->boxMenuHeight) / 2};
    printEndLine(verticalPadding);

    printLeftPadding();
    std::cout << this->white << boxLid << std::endl;
    for (unsigned short i = 0; i < this->menuString.size(); ++i) {
        printLeftPadding();
        if (this->menuState + 2 == i) {
            std::cout << "│" << menuString[i] << "│" << std::endl;
        } else {
            std::cout << "│" << this->lightGray << menuString[i] << this->white
                      << "│" << std::endl;
        }
    }
    printLeftPadding();
    std::cout << boxBottom << std::endl;

    printLeftPadding();
    std::cout << this->white << "wasd  " << this->lightGray << "move"
              << this->white << "   #  <─┘" << this->lightGray << " Confirm";
    printEndLine(verticalPadding - 2);
}

void UserInterface::printScreen() {
    if (this->state == 0) {
        printMenu();
    }
}