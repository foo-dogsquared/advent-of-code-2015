#include <iostream>
#include <fstream>
#include <map>

// one of the main key for this challenge is to think about the grid
// as in a literal Cartesian plane which means we need to consider the coordinates
// and other Cartesian plane-related... stuff
int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "Usage: <filePath>" << std::endl;
        return 1;
    }

    std::ifstream input(argv[1]);

    // let's make Santa at the center which means he's at the origin
    int x = 0;
    int y = 0;

    // let's make a list of coordinates which represents the houses Santa already visited along with the number of times he gave them gifts
    std::map<std::string, int> coordinates_of_visited_houses;

    // Santa already gave a gift at House <0, 0> so let's add that to our associated array of the coordinates of houses
    // that he visited and already gave a gift
    coordinates_of_visited_houses.insert(std::make_pair(std::to_string(x) + ":" + std::to_string(y), 1));

    // parsing through the input
    for (char c; input.get(c);) {
        switch (c) {
            case '^':
                y++;
                break;
            case 'v':
                y--;
                break;
            case '>':
                x++;
                break;
            case '<':
                x--;
                break;
        }

        std::string coordinate = std::to_string(x) + ":" + std::to_string(y);

        coordinates_of_visited_houses[coordinate]++;

        std::cout << coordinate << std::endl;
    }

    std::cout << "Santa visited " << coordinates_of_visited_houses.size() << " houses." << std::endl;

    return 0;
}