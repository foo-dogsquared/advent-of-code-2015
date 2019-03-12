#include <iostream>
#include <fstream>
#include <regex>
#include <cmath>

int rectangle_perimeter(int length, int width);
int right_rectangular_prism_volume(int length, int width, int height);

int main() {
    std::ifstream input_file("input.txt");

    std::regex polyhedra_dimension("(\\d+)x(\\d+)x(\\d+)");
    int total_ribbon_length = 0;
    for (std::string line; std::getline(input_file, line);) {
        std::smatch matches;
        std::regex_match(line, matches, polyhedra_dimension);
        int length = stod(matches[1]);
        int width = stod(matches[2]);
        int height = stod(matches[3]);
        // a right rectangular prism has 3 distinct faces, all of which are rectangles
        // which means we have 3 rectangles perimeters to compute
        int face1 = rectangle_perimeter(length, width);
        int face2 = rectangle_perimeter(width, height);
        int face3 = rectangle_perimeter(length, height);
        total_ribbon_length += std::min({ face1, face2, face3 });

        // for the bow
        total_ribbon_length += right_rectangular_prism_volume(length, width, height);
    }

    std::cout << "Total length of the ribbon they order is " << total_ribbon_length << std::endl;
    return 0;
}

// formula of the rectangle perimeter
int rectangle_perimeter(int length, int width) {
    return (2 * length) + (2 * width);
}

int right_rectangular_prism_volume(int length, int width, int height) {
    return length * width * height;
}
