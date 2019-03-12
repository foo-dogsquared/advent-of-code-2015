#include <fstream>
#include <iostream>
#include <regex>
#include <cmath>

double right_rectangular_prism_area(double length, double width, double height);

int main() {
    std::ifstream input_file("input.txt");

    std::regex polyhedra_dimension("(\\d+)x(\\d+)x(\\d+)");
    int total_surface_area = 0;
    for (std::string line; std::getline(input_file, line);) {
        std::smatch matches;
        std::regex_match(line, matches, polyhedra_dimension);
        double length = std::stod(matches[1]);
        double width = std::stod(matches[2]);
        double height = std::stod(matches[3]);
        std::cout << right_rectangular_prism_area(length, width, height) << std::endl;
        total_surface_area += right_rectangular_prism_area(length, width, height);
        total_surface_area += std::min({(length * width), (width * height), (length * height)});
    }

    std::cout << "Total surface area to order: " << total_surface_area << std::endl;
    return 0;
}

double right_rectangular_prism_area(double length, double width, double height) {
    return (2 * (length * width)) + (2 * (width * height)) + (2 * (length * height));
}
