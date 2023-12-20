#include <sys/ioctl.h>

#include <iostream>
#include <string>
#include <vector>

void centerify_output(std::string str, int num_cols) {
    // Calculate left padding
    int padding_left = (num_cols / 2) - (31 / 2);

    // Put padding spaces
    for (int i = 0; i < padding_left; ++i) std::cout << ' ';

    // Print the message
    std::cout << str;
}

int main() {
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);

    printf("lines %d\n", w.ws_row);
    printf("columns %d\n", w.ws_col);

    std::vector<std::string> lines = {
        "┌─────────────────────────┐", "│                         │",
        "│         P L A Y         │", "│     S E T T I N G S     │",
        "│   S T A T I S T I C S   │", "│         Q U I T         │",
        "│                         │", "└─────────────────────────┘",
    };

    // OUTPUT
    for (int i = 0; i < lines.size(); ++i) {
        centerify_output(lines[i], w.ws_col);
        std::cout << std::endl;
    }
}