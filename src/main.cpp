#include <bits/stdc++.h>
// #include <chrono>

// #include "cube/RubiksCube3dArray.cpp"
#include "cube/RubiksCube1dArray.cpp"
// #include "cube/RubiksCubeBitboard.cpp"
using namespace std;

int main(){
    srand(time(0));     // seed for the random function
    auto start = chrono::high_resolution_clock::now();

    cout << "Setup working!" << endl;

    // RubiksCube3dArray cube;

    // RubiksCube1dArray cube;

    // RubiksCubeBitboard cube;

    // ---------------- Move Testing -----------------------

    // auto moves = cube.randomShuffleRubiksCube(10);
    // cout << "Moves Applied :" << endl;
    // for(auto it : moves){
    //     cout << RubiksCube::getMove(it) << " ";
    // }
    // cout << endl;
    // cube.print();
    // for(auto it = moves.rbegin(); it != moves.rend(); it++){
    //     cube.invert(*it);
    // }
    // assert(cube.isSolved());
    // // cube.u();
    // // cube.l();
    // // cube.f();
    // // cube.r();
    // // cube.b();
    // // cube.d();
    // cube.print();

    // ----------------------------------------------------------------------------

    // RubiksCube3dArray r1;
    // RubiksCube3dArray r2;
    
    RubiksCube1dArray r1;
    RubiksCube1dArray r2;

    // ---------------- Comparison & Assignment Operator Testing -------------------
    
    // if(r1 == r2) cout << "EQUAL" << endl;
    // else cout << "NOT EQUAL" << endl;

    // r1.randomShuffleRubiksCube(1);

    // if(r1 == r2) cout << "EQUAL" << endl;
    // else cout << "NOT EQUAL" << endl;

    // r1 = r2;
    // if(r1 == r2) cout << "EQUAL" << endl;
    // else cout << "NOT EQUAL" << endl;

    // ---------------- Unordered Map Testing -------------------------

    // unordered_map<RubiksCube3dArray, bool, Hash3dArray> mpp;

    unordered_map<RubiksCube1dArray, bool, Hash1dArray> mpp;
    
    r1.randomShuffleRubiksCube(7);
    r2.randomShuffleRubiksCube(7);

    mpp[r1] = true;
    if(mpp.find(r1) != mpp.end()) cout << "R1 present" << endl;
    else cout << "R1 absent" << endl;
    if(mpp.find(r2) != mpp.end()) cout << "R2 present" << endl;
    else cout << "R2 absent" << endl;
    

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    cout << "Execution time: " << duration.count() << " ms" << endl;
    return 0;
}