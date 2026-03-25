#include <bits/stdc++.h>
// #include <chrono>

// #include "cube/RubiksCube3dArray.cpp"
#include "cube/RubiksCube1dArray.cpp"
#include "cube/RubiksCubeBitboard.cpp"
using namespace std;

int main(){
    srand(time(0));     // seed for the random function
    auto start = chrono::high_resolution_clock::now();

    cout << "Setup working!" << endl;

    // RubiksCube3dArray cube;

    // RubiksCube1dArray cube;

    RubiksCubeBitboard cube;

    auto moves = cube.randomShuffleRubiksCube(10);
    cout << "Moves Applied :" << endl;
    for(auto it : moves){
        cout << RubiksCube::getMove(it) << " ";
    }
    cout << endl;
    cube.print();
    for(auto it = moves.rbegin(); it != moves.rend(); it++){
        cube.invert(*it);
    }
    assert(cube.isSolved());
    // cube.u();
    // cube.l();
    // cube.f();
    // cube.r();
    // cube.b();
    // cube.d();
    cube.print();

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    cout << "Execution time: " << duration.count() << " ms" << endl;
    return 0;
}