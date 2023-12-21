// ┌───┐
// │ A │
// └───┘
#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <string>
#include <vector>

class UserInterface {
   public:
    UserInterface();

    int getWinSize();

    void printLeftPadding();
    void printScreen();
    void printMenu();
    void printEndLine(int l);

    void readInput();

   private:
    int state;
    int menuState;
    bool invalidOpt;

    std::string boxEmpty;
    std::string boxLid;
    std::string boxBottom;

    int winWidth;
    int winHeight;
    int leftPadding;
    std::vector<std::string> menuString;

    constexpr static int boxWidth{31};
    constexpr static int boxMenuHeight{17};

    // colors
    static const std::string white;
    static const std::string lightGray;
    static const std::string green;
    static const std::string yellow;
    static const std::string orange;
    static const std::string tan;
};

#endif