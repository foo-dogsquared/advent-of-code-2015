#include <fstream>
#include <iostream>

int main() {
    std::ifstream input_file("input.txt");
    
    int floor = 0;
    int position = 0;
    for (char c; floor > -1 && input_file.get(c);) {
        if (c == '(') floor++;
        else if (c == ')') floor--;
        position++;
        std::cout << "At position " << position << ": " << floor << std::endl;
    }

    std::cout << "Santa first enter the basement at position " << position << std::endl;
    return 0;
}