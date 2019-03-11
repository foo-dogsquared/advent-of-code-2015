#include <fstream>
#include <iostream>

int main() {
    std::fstream input_file("input.txt");
    int floor = 0;
    char c1;
    for (char c; input_file.get(c);) {
        if (c == '(') floor++;
        else if (c == ')') floor--;
    }

    std::cout << floor << std::endl;
    return 0;
}
