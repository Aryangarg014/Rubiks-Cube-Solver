#include<bits/stdc++.h>

#include "CornerDBMaker.h"
using namespace std;

CornerDBMaker::CornerDBMaker(string fileName){
    this -> fileName = fileName;
}

void CornerDBMaker::bfsAndStore(){

    RubiksCubeBitboard solvedCube;

    queue<RubiksCubeBitboard> q;
    q.push(solvedCube);
    cornerDB.setNumMoves(solvedCube, 0);
    int curDepth = 0;
    while(!q.empty()){
        int levelSize = q.size();

        if(curDepth == 8) break;

        for(int i=0; i<levelSize; i++){
            RubiksCubeBitboard node = q.front();
            q.pop();

            for(int j=0; j<18; j++){
                auto curMove = RubiksCube::MOVE(j);
                node.move(curMove);
                // if already set (found at less depth) then do nothing
                // if not already set then set the num of moves to curDepth + 1 and push into queue
                if(cornerDB.setNumMoves(node, curDepth + 1)){
                    q.push(node);
                }
                node.invert(curMove);
            }
        }
        curDepth++;
    }
    cornerDB.toFile(fileName);
}