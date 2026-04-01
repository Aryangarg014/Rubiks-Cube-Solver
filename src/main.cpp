#include <bits/stdc++.h>
// #include <chrono>

#include "cube/RubiksCube.h"
#include "cube/RubiksCube3dArray.h"
#include "cube/RubiksCube1dArray.h"
#include "cube/RubiksCubeBitboard.h"
// #include "solver/DFSSolver.h"
// #include "solver/BFSSolver.h"
// #include "solver/IDDFSSolver.h"
#include "solver/IDAStarSolver.h"
// #include "PatternDatabase/CornerPatternDatabase.h"
#include "PatternDatabase/CornerDBMaker.h"

using namespace std;

// // Apply a given sequence of moves to any cube representation
// template<typename T>
// void applyMoves(T &cube, const vector<RubiksCube::MOVE> &moves){
//     for(auto &move : moves){
//         cube.move(move);
//     }
// }

// // Print move list
// void printMoves(const vector<RubiksCube::MOVE> &moves){
//     for(auto &move : moves){
//         cout << RubiksCube::getMove(move) << " ";
//     }
//     cout << endl;
// }


// // ------------------------ DFS TEST FUNCTION ------------------------
// template<typename T, typename H>
// void testDFSSolver(string name, T cube, int maxDepth){
//     cout << "===============================" << endl;
//     cout << "Testing " << name << endl;

//     auto start = chrono::high_resolution_clock::now();

//     DFSSolver<T, H> solver(cube, maxDepth);
//     auto solution = solver.solve();

//     auto end = chrono::high_resolution_clock::now();
//     auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

//     cout << "Moves To Solve: ";
//     printMoves(solution);
//     cout << "Number Of Moves: " << solution.size() << endl;
//     cout << "Execution Time: " << duration.count() << " ms" << endl;
//     cout << "===============================" << endl << endl;
// }

// // ------------------------ IDDFS TEST FUNCTION ------------------------
// template<typename T, typename H>
// void testIDDFSSolver(string name, T cube, int maxDepth){
//     cout << "===============================" << endl;
//     cout << "Testing " << name << endl;

//     auto start = chrono::high_resolution_clock::now();

//     IDDFSSolver<T, H> solver(cube, maxDepth);
//     auto solution = solver.solve();

//     auto end = chrono::high_resolution_clock::now();
//     auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

//     cout << "Moves To Solve: ";
//     printMoves(solution);
//     cout << "Number Of Moves: " << solution.size() << endl;
//     cout << "Execution Time: " << duration.count() << " ms" << endl;
//     cout << "===============================" << endl << endl;
// }

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
    
    // RubiksCube1dArray r1;
    // RubiksCube1dArray r2;

    // RubiksCubeBitboard r1;
    // RubiksCubeBitboard r2;

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

    // unordered_map<RubiksCube1dArray, bool, Hash1dArray> mpp;

    // unordered_map<RubiksCubeBitboard, bool, HashBitboard> mpp;
    
    // r1.randomShuffleRubiksCube(7);
    // r2.randomShuffleRubiksCube(7);

    // mpp[r1] = true;
    // if(mpp.find(r1) != mpp.end()) cout << "R1 present" << endl;
    // else cout << "R1 absent" << endl;
    // if(mpp.find(r2) != mpp.end()) cout << "R2 present" << endl;
    // else cout << "R2 absent" << endl;

    // -------------------- BFS Solver Testing ------------------------
    // RubiksCubeBitboard r;
    // auto moves1 = r.randomShuffleRubiksCube(6);
    
    // cout << "Moves Applied: ";
    // for(auto &move : moves1){
    //     cout << RubiksCube1dArray::getMove(move) << " ";
    // }
    // cout << endl;
    // r.print();

    // BFSSolver<RubiksCubeBitboard, HashBitboard> solver(r);
    // auto moves = solver.solve();

    // cout << "Moves To Solve: ";
    // for(auto &move : moves){
    //     cout << RubiksCubeBitboard::getMove(move) << " ";
    // }
    // cout << endl;


    // // -------------------- Generate SAME shuffle ------------------------
    // int shuffleDepth = 6;
    // int solverDepth = 8;

    // RubiksCube3dArray tempCube;
    // auto shuffleMoves = tempCube.randomShuffleRubiksCube(shuffleDepth);
    
    // cout << "Moves Applied: ";
    // printMoves(shuffleMoves);
    // cout << endl;

    // // -------------------- Create Cubes ------------------------
    // RubiksCube3dArray cube3d;
    // RubiksCube1dArray cube1d;
    // RubiksCubeBitboard cubeBit;

    // // Apply same shuffle to all 3
    // applyMoves(cube3d, shuffleMoves);
    // applyMoves(cube1d, shuffleMoves);
    // applyMoves(cubeBit, shuffleMoves);

    // // Optional: print only one cube for verification
    // cout << "shuffled Cube:" << endl;
    // cube3d.print();

    // // -------------------- DFS Solver Testing ------------------------

    // testDFSSolver<RubiksCubeBitboard, HashBitboard>("Bitboard", cubeBit, solverDepth);
    // testDFSSolver<RubiksCube1dArray, Hash1dArray>("1D Array", cube1d, solverDepth);
    // testDFSSolver<RubiksCube3dArray, Hash3dArray>("3D Array", cube3d, solverDepth);



    // // -------------------------- IDDFS Solver Testing --------------------------

    // testIDDFSSolver<RubiksCubeBitboard, HashBitboard>("Bitboard", cubeBit, solverDepth);
    // testIDDFSSolver<RubiksCube1dArray, Hash1dArray>("1D Array", cube1d, solverDepth);
    // testIDDFSSolver<RubiksCube3dArray, Hash3dArray>("3D Array", cube3d, solverDepth);


    // // -------------------------- IDA* Solver Testing ----------------------------
    // RubiksCubeBitboard cube;
    // cube.print();
    // auto shuffle_moves = cube.randomShuffleRubiksCube(5);
    // cout << "Moves Applied: ";
    // for(auto mv : shuffle_moves) cout << cube.getMove(mv) << " ";
    // cout << endl;

    // cube.print();

    // IDAStarSolver<RubiksCubeBitboard, HashBitboard> solver(cube);
    // vector<RubiksCube::MOVE> movesToSolve = solver.solve();
    // cout << "Moves To Solve: ";
    // for(auto mv : movesToSolve) cout << cube.getMove(mv) << " ";
    // cout << endl;

    // solver.cube.print();

    string dbFile = "C:\\Users\\garga\\Desktop\\Rubiks-Cube-Solver\\Databases\\cornerDepth8.bin";

    // Generate DB only if file does not exist
    ifstream fin(dbFile, ios::binary);
    if(!fin){
        cout << "Pattern DB file not found. Generating...\n";
        CornerDBMaker dbMaker(dbFile);
        dbMaker.bfsAndStore();
    }
    else{
        cout << "Pattern DB file already exists. Using stored database.\n";
        fin.close();
    }

    RubiksCube3dArray cube;
    auto shuffleMoves = cube.randomShuffleRubiksCube(8);

    cout << "Moves Applied: ";
    for(auto &mv : shuffleMoves){
        cout << RubiksCube::getMove(mv) << " ";
    }
    cout << endl;
    // cout << "Scrambled cube:\n";
    cube.print();

    IDAStarSolver<RubiksCube3dArray, Hash3dArray> solver(cube, dbFile);
    vector<RubiksCube::MOVE> ans = solver.solve();

    cout << "Solved Cube: " << endl;
    solver.cube.print();

    cout << "Solution moves: ";
    for(auto mv : ans){
        cout << RubiksCube::getMove(mv) << " ";
    }
    cout << endl;

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    cout << "Execution time: " << duration.count() << " ms" << endl;
    return 0;
}