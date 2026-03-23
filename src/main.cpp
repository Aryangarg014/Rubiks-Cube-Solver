#include <bits/stdc++.h>
#include "cube/RubiksCube3dArray.cpp"
// #include <chrono>
using namespace std;

int main(){
    srand(time(0));     // seed for the random function
    auto start = chrono::high_resolution_clock::now();

    cout << "Setup working!" << endl;

    RubiksCube3dArray cube;
    // cube.print();
    // cube.l();
    // cube.l_prime();
    // cube.u();
    // cube.u_prime();
    // cube.r();
    // cube.d();
    // cube.b();
    // cube.f();
    // cube.l2();
    // cube.l2();

    auto moves = cube.randomShuffleRubiksCube(10);
    cout << "Moves Applied :" << endl;
    for(auto it : moves){
        cout << RubiksCube3dArray::getMove(it) << " ";
    }
    cout << endl;
    cube.print();
    for(auto it = moves.rbegin(); it != moves.rend(); it++){
        cube.invert(*it);
    }
    assert(cube.isSolved());
    cube.print();

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    cout << "Execution time: " << duration.count() << " ms" << endl;
    return 0;
}