#include <bits/stdc++.h>
#include "cube/RubiksCube3dArray.cpp"
// #include <chrono>
using namespace std;

int main(){
    srand(time(0));     // seed for the random function
    auto start = chrono::high_resolution_clock::now();

    cout << "Setup working!" << endl;

    RubiksCube3dArray cube;
    cube.print();
    // cube.l();
    cube.u();
    cube.print();

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    cout << "Execution time: " << duration.count() << " ms" << endl;
    return 0;
}