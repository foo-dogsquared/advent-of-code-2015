#include <iostream>
#include <fstream>
#include <map>
#include <vector>

typedef struct _santa {
    int x;
    int y;
}
Santa;

void move_santa(Santa &santa, int x, int y) {
    santa.x = x;
    santa.y = y;
}

// just like the previous part of the challenge, we'll think of this as a grid,
// a Cartesian plane, in other words except we have two persons to deal with
int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "Usage: [inputPath].txt" << std::endl;
    }

    // let's take an input stream of directions from the elf (which is you, I think...)
    std::ifstream input(argv[1]);

    // since the problem set dictates that each turn represents a Santa, it's also a perfect fit
    // to consider a formula: 
    // pos % n = N
    // where "pos" is the position in the input stream
    // and "n" is the number of santas roaming around the grid of houses
    // whatever the results is the "N"th Santa that's going to make the move
    
    // since each Santa is going to be in its own position doing their own stuff,
    // let's make an abstraction class for this which is indicated in the top of this file

    // since each of them take a turn and with the formula integration, I think it is better to put them in a vector
    // also, it serves as an easier way to access them
    std::vector<Santa> santas;

    // we have two santas so, let's add them into the list
    for (int index = 0; index < 2; index++) {
        Santa santa;
        santa.x = 0;
        santa.y = 0;

        santas.push_back(santa);
    }

    // the problem asks for the number of houses they've visited so let's incorporate 
    // a map that lists the house they've previously visited
    std::map<std::string, int> coordinates_of_visited_houses;

    // also they've already visited the house at origin so let's do that
    coordinates_of_visited_houses["0:0"]++;

    // let's add a variable to keep track of the position of the cursor
    // it's going to read an input at the very start so let's initialize at value 0
    int cursor_position = 0;
    int santas_count = santas.size();

    // now, let's command them with the input stream
    for (char c; input.get(c); cursor_position++) {
        // same case as before except we have to keep track of the current santa
        Santa *current_santa = &santas[cursor_position % santas_count];

        switch (c) {
            case '^':
                current_santa->y++;
                break;
            case 'v':
                current_santa->y--;
                break;
            case '>':
                current_santa->x++;
                break;
            case '<':
                current_santa->x--;
                break;
        }

        std::string current_santa_coordinate = std::to_string(current_santa->x) + ":" + std::to_string(current_santa->y);
        std::cout << current_santa_coordinate << std::endl;

        coordinates_of_visited_houses[current_santa_coordinate]++;
    }

    std::cout << "All santas have visited a total of " << coordinates_of_visited_houses.size() << " houses." << std::endl;

    return 0;
}
