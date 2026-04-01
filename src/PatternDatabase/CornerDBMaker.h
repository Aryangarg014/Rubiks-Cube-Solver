#pragma once
#include<bits/stdc++.h>

#include "CornerPatternDatabase.h"
#include "../cube/RubiksCubeBitboard.h"
using namespace std;

class CornerDBMaker{

private:
    CornerPatternDatabase cornerDB;
    string fileName;
public:
    CornerDBMaker(string fileName);

    // generate the corner pattern database using BFS and store in the file
    void bfsAndStore();

};