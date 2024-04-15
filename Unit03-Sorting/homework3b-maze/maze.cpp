#include <iostream>
#include <string>
#include <fstream>
// if this was in my linux directory would it work?
#include "Grid.h"
#include <vector>
using namespace std;

bool InBounds(int x, int y, int z, Grid maze){
    if ( x < 0 || x-1 > maze.width()) { return false;}
    if ( y < 0 || y-1 > maze.height()) { return false;}
    if ( z < 0 || z-1 > maze.depth()) { return false;}
    return true;
}

void Solve(vector<vector<int>> &solution, vector<int> position, Grid& maze) {
    int x = position[0];
    int y = position[1];
    int z = position[2];
    int a =  maze.width();
    int b = maze.height();
    int c = maze.depth();
    // base cases
    if (x == a-1 && y == b-1 && z == c-1) {
        solution.push_back({x, y, z});
        return;
    }
    if (maze.at(x, y, z) == 0 ) {
        vector<vector<int>> failure = {};
        return;
    }

    // iterate through surrounding positions, see if they are available
    if (InBounds(x-1, y, z, maze) && maze.at(x-1, y, z) == 1) {
        cout << "got here" << endl;
        // go onwards
        // recursive call that will return filled solution if got to end, empty otherwise

        Solve(solution, {x-1, y, z}, maze); // try move, when it returns check status of solution
        if (!solution.empty()) {                            // if solution is empty, end not found, go to next possible move
                                                            // if solution is not empty, push_back that position that worked and return
            solution.push_back({x - 1, y, z});
            return;
        }

        // else, try next move
    }

    else if (InBounds(x+1, y, z, maze) && maze.at(x-1, y, z) == 1) {
        cout << "got here" << endl;

        Solve(solution, {x+1, y, z}, maze);
        if (!solution.empty()) {                            // if solution is empty, end not found, go to next possible move

            solution.push_back({x + 1, y, z});
            return;
        }

        // else, try next move
    }
//    else if (InBounds(x, y-1, z, maze) && maze.at(x, y-1, z) == 1) {
//        if (!Solve(solution, {x, y-1, z}, maze).empty()){ // if not empty, keep returning
//            solution = Solve(solution, position, maze);
//            solution.push_back({x, y-1, z});
//            return solution;
//        }
//    }
//    else if (InBounds(x, y+1, z, maze) && maze.at(x, y+1, z) == 1) {
//        if (!Solve(solution, {x, y+1, z}, maze).empty()){ // if not empty, keep returning
//            solution = Solve(solution, position, maze);
//            solution.push_back({x, y+1, z});
//            return solution;
//        }
//    }
//    else if (InBounds(x, y, z-1, maze) && maze.at(x, y, z-1) == 1) {
//        if (!Solve(solution, {x, y, z-1}, maze).empty()){ // if not empty, keep returning
//            solution = Solve(solution, position, maze);
//            solution.push_back({x, y, z-1});
//            return solution;
//        }
//    }
//    else if (InBounds(x, y, z+1, maze) && maze.at(x, y, z+1) == 1) {
//        if (!Solve(solution, {x, y, z+1}, maze).empty()){ // if not empty, keep returning
//            solution = Solve(solution, position, maze);
//            solution.push_back({x, y, z+1});
//            return solution;
//        }
//    }

//    solution.push_back(new_position);
    vector<vector<int>> nada = {};
    return;
}


int main(int argc, char* argv[]) {
    cout << "test" << endl;

    string filename = argv[1];
    cout << "filename: " << filename << endl;

    std::ifstream in(filename);
//    // get the dimensions
//    int w; int h; int d; // width, height, depth
////    in >> w; in >> h; in >> d;
    Grid maze;

    in >> maze;

    std::cout << "The maze is " << maze.height() << " spaces tall, "
    << maze.width() << " spaces wide, and " << maze.depth() << " spaces deep." << std::endl;


    vector<vector<int>> problem = {};
    cout << InBounds(1, 3, 0, maze);
    Solve(problem, {0, 0, 0}, maze);
    cout << maze.at(1, 2, 1);
    cout << problem.back().back();

    // try moving in d1

        // worked? continue. d1 again
        //no? return false, try next
    return 0;
}
