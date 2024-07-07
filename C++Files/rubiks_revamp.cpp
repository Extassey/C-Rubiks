#include <iostream>
#include <string>

void printRow(const std::string& color) {
    std::cout << " _______ _______ _______ \n";
    std::cout << "|       |       |       |\n";
    std::cout << "| " << color << " | " << color << " | " << color << " |\n";
    std::cout << "|_______|_______|_______|\n";
}

int main() {
    // Print the RED rows
    for (int i = 0; i < 3; ++i) {
        printRow(" RED ");
    }
    std::cout << " _______ _______ _______ \n";

    // Print the white rows
    for (int i = 0; i < 3; ++i) {
        printRow("white");
    }
    std::cout << " _______ _______ _______ \n";

    // Print the BLUE rows
    for (int i = 0; i < 3; ++i) {
        printRow("BLUE ");
    }
    std::cout << " _______ _______ _______ \n";

    return 0;
}
