// #include <bits/stdc++.h>
// // #include <chrono>

// #include "cube/RubiksCube.h"
// #include "cube/RubiksCube3dArray.cpp"
// // #include "cube/RubiksCube1dArray.cpp"
// // #include "cube/RubiksCubeBitboard.cpp"
// #include "solver/DFSSolver.h"
// using namespace std;

// int main(){
//     srand(time(0));     // seed for the random function
//     auto start = chrono::high_resolution_clock::now();

//     cout << "Setup working!" << endl;

//     // RubiksCube3dArray cube;

//     // RubiksCube1dArray cube;

//     // RubiksCubeBitboard cube;

//     // ---------------- Move Testing -----------------------

//     // auto moves = cube.randomShuffleRubiksCube(10);
//     // cout << "Moves Applied :" << endl;
//     // for(auto it : moves){
//     //     cout << RubiksCube::getMove(it) << " ";
//     // }
//     // cout << endl;
//     // cube.print();
//     // for(auto it = moves.rbegin(); it != moves.rend(); it++){
//     //     cube.invert(*it);
//     // }
//     // assert(cube.isSolved());
//     // // cube.u();
//     // // cube.l();
//     // // cube.f();
//     // // cube.r();
//     // // cube.b();
//     // // cube.d();
//     // cube.print();

//     // ----------------------------------------------------------------------------

//     // RubiksCube3dArray r1;
//     // RubiksCube3dArray r2;
    
//     // RubiksCube1dArray r1;
//     // RubiksCube1dArray r2;

//     // RubiksCubeBitboard r1;
//     // RubiksCubeBitboard r2;

//     // ---------------- Comparison & Assignment Operator Testing -------------------
    
//     // if(r1 == r2) cout << "EQUAL" << endl;
//     // else cout << "NOT EQUAL" << endl;

//     // r1.randomShuffleRubiksCube(1);

//     // if(r1 == r2) cout << "EQUAL" << endl;
//     // else cout << "NOT EQUAL" << endl;

//     // r1 = r2;
//     // if(r1 == r2) cout << "EQUAL" << endl;
//     // else cout << "NOT EQUAL" << endl;

//     // ---------------- Unordered Map Testing -------------------------

//     // unordered_map<RubiksCube3dArray, bool, Hash3dArray> mpp;

//     // unordered_map<RubiksCube1dArray, bool, Hash1dArray> mpp;

//     // unordered_map<RubiksCubeBitboard, bool, HashBitboard> mpp;
    
//     // r1.randomShuffleRubiksCube(7);
//     // r2.randomShuffleRubiksCube(7);

//     // mpp[r1] = true;
//     // if(mpp.find(r1) != mpp.end()) cout << "R1 present" << endl;
//     // else cout << "R1 absent" << endl;
//     // if(mpp.find(r2) != mpp.end()) cout << "R2 present" << endl;
//     // else cout << "R2 absent" << endl;

//     // -------------------- DFS Solver Testing ------------------------
//     RubiksCube3dArray r;
//     auto moves1 = r.randomShuffleRubiksCube(6);
    
//     cout << "Moves Applied: ";
//     for(auto &move : moves1){
//         cout << RubiksCube3dArray::getMove(move) << " ";
//     }
//     cout << endl;
//     r.print();

//     DFSSolver<RubiksCube3dArray, Hash3dArray> solver(r, 8);
//     auto moves = solver.solve();

//     cout << "Moves To Solve: ";
//     for(auto &move : moves){
//         cout << RubiksCube3dArray::getMove(move) << " ";
//     }
//     cout << endl;

//     auto end = chrono::high_resolution_clock::now();
//     auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

//     cout << "Execution time: " << duration.count() << " ms" << endl;
//     return 0;
// }


#include <bits/stdc++.h>
#include <chrono>

#include "cube/RubiksCube.h"
#include "cube/RubiksCube3dArray.cpp"
#include "cube/RubiksCube1dArray.cpp"
#include "cube/RubiksCubeBitboard.cpp"
#include "solver/DFSSolver.h"

using namespace std;

// Apply a given sequence of moves to any cube representation
template<typename T>
void applyMoves(T &cube, const vector<RubiksCube::MOVE> &moves){
    for(auto &move : moves){
        cube.move(move);
    }
}

// Print move list
void printMoves(const vector<RubiksCube::MOVE> &moves){
    for(auto &move : moves){
        cout << RubiksCube::getMove(move) << " ";
    }
    cout << endl;
}

// Test one cube representation
template<typename T, typename H>
void testSolver(string name, T cube, int maxDepth){
    cout << "===============================" << endl;
    cout << "Testing " << name << endl;

    auto start = chrono::high_resolution_clock::now();

    DFSSolver<T, H> solver(cube, maxDepth);
    auto solution = solver.solve();

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    cout << "Moves To Solve: ";
    printMoves(solution);
    cout << "Number Of Moves: " << solution.size() << endl;
    cout << "Execution Time: " << duration.count() << " ms" << endl;
    cout << "===============================" << endl << endl;
}

int main(){
    srand(time(0));     // seed for random shuffle

    cout << "Setup working!" << endl;

    int shuffleDepth = 6;
    int solverDepth = 8;

    // -------------------- Generate SAME shuffle ------------------------
    RubiksCube3dArray tempCube;
    auto shuffleMoves = tempCube.randomShuffleRubiksCube(shuffleDepth);

    cout << "Moves Applied: ";
    printMoves(shuffleMoves);
    cout << endl;

    // -------------------- Create Cubes ------------------------
    RubiksCube3dArray cube3d;
    RubiksCube1dArray cube1d;
    RubiksCubeBitboard cubeBit;

    // Apply same shuffle to all 3
    applyMoves(cube3d, shuffleMoves);
    applyMoves(cube1d, shuffleMoves);
    applyMoves(cubeBit, shuffleMoves);

    // Optional: print only one cube for verification
    cout << "shuffled Cube:" << endl;
    cube3d.print();

    // -------------------- DFS Solver Testing ------------------------
    testSolver<RubiksCube3dArray, Hash3dArray>("3D Array", cube3d, solverDepth);
    testSolver<RubiksCube1dArray, Hash1dArray>("1D Array", cube1d, solverDepth);
    testSolver<RubiksCubeBitboard, HashBitboard>("Bitboard", cubeBit, solverDepth);

    return 0;
}