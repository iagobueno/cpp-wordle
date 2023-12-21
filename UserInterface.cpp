#include "UserInterface.hpp"

#include <sys/ioctl.h>

#include <iostream>

const std::string UserInterface::white = "\033[1;37m";
const std::string UserInterface::lightGray = "\033[38:5:8m";
const std::string UserInterface::green = "\033[1;32m";
const std::string UserInterface::yellow = "\033[1;33m";
const std::string UserInterface::orange = "\033[38:5:166m";

UserInterface::UserInterface() : state{0}, menuState{0}, invalidOpt{false} {
    // get window size
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    this->winWidth = w.ws_col;
    this->winHeight = w.ws_row;

    // calculate left padding
    this->leftPadding = (winWidth / 2) - (this->boxWidth / 2);

    boxEmpty = "│                         │";
    boxLid = "┌─────────────────────────┐";
    boxBottom = "└─────────────────────────┘";
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
    std::cout << this->green << "            Z A" << std::endl;
    printLeftPadding();
    std::cout << this->yellow << "        W O R D L E" << std::endl;

    printLeftPadding();
    std::cout << this->lightGray << boxLid << std::endl;
    printLeftPadding();
    std::cout << this->boxEmpty << std::endl;

    printLeftPadding();
    std::cout << "│         options:        │" << std::endl;
    printLeftPadding();
    std::cout << this->boxEmpty << std::endl;
    printLeftPadding();
    std::cout << this->lightGray << "│" << this->white << "   p        "
              << this->lightGray << "      Play   │" << std::endl;
    printLeftPadding();
    std::cout << this->lightGray << "│" << this->white << "   s        "
              << this->lightGray << "  Settings   │" << std::endl;
    printLeftPadding();
    std::cout << this->lightGray << "│" << this->white << "   t        "
              << this->lightGray << "Statistics   │" << std::endl;
    printLeftPadding();
    std::cout << this->lightGray << "│" << this->white << "   h        "
              << this->lightGray << "      Help   │" << std::endl;
    printLeftPadding();
    std::cout << this->lightGray << "│" << this->white << "   q        "
              << this->lightGray << "      Quit   │" << std::endl;

    for (unsigned short i = 0; i < 3; ++i) {
        printLeftPadding();
        if (i == 1 && this->invalidOpt == true) {
            std::cout << "│    invalid option!      │" << std::endl;
        } else {
            std::cout << this->boxEmpty << std::endl;
        }
    }

    printLeftPadding();
    std::cout << boxBottom << std::endl;

    printLeftPadding();
    std::cout << this->white << "enter" << this->lightGray
              << "     to submit option" << std::endl;

    printEndLine(verticalPadding);
}

void UserInterface::readInput() {
    std::string buffer;
    std::cin >> buffer;

    if (buffer.size() > 1) {
        invalidOpt = true;
        return;
    }

    if (buffer == "p") {
        this->state = 1;
    } else if (buffer == "s") {
        this->state = 2;
    } else if (buffer == "t") {
        this->state = 3;
    } else if (buffer == "h") {
        this->state = 4;
    } else if (buffer == "q") {
        this->state = 5;
    }

    return;
}

void UserInterface::printScreen() {
    if (this->state == 0) {
        printMenu();
    }
}