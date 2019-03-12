#include <fstream>
#include <iostream>
#include <regex>
#include <cmath>

int right_rectangular_prism_area(int length, int width, int height);

int main() {
    std::ifstream input_file("input.txt");

    std::regex polyhedra_dimension("(\\d+)x(\\d+)x(\\d+)");
    int total_surface_area = 0;
    for (std::string line; std::getline(input_file, line);) {
        std::smatch matches;
        std::regex_match(line, matches, polyhedra_dimension);
        int length = std::stod(matches[1]);
        int width = std::stod(matches[2]);
        int height = std::stod(matches[3]);
        std::cout << right_rectangular_prism_area(length, width, height) << std::endl;
        total_surface_area += right_rectangular_prism_area(length, width, height);
        total_surface_area += std::min({(length * width), (width * height), (length * height)});
    }

    std::cout << "Total surface area to order: " << total_surface_area << std::endl;
    return 0;
}

int right_rectangular_prism_area(int length, int width, int height) {
    return (2 * (length * width)) + (2 * (width * height)) + (2 * (length * height));
}
