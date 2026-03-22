#include<bits/stdc++.h>

#include "RubiksCube.h"
using namespace std;

class RubiksCube3dArray : public RubiksCube{

private:
    vector<vector<vector<char>>> cube;

    void rotateFace(int face){
        vector<vector<char>> temp = cube[face];
        for(int i=2; i>=0; i--){
            for(int j=0; j<3; j++){
                cube[face][j][2-i] = temp[i][j];
            }
        }
    }

public:
/*
Solved Rubiks Cube
    Indexing of Faces
        Up → 0 (White)
        Left → 1 (Green)
        Front → 2 (Red)
        Right → 3 (Blue)
        Back → 4 (Orange)
        Down → 5 (Yellow)
*/


    // initialize the solved RubiksCube
    RubiksCube3dArray(){
        cube.resize(6, vector<vector<char>>(3, vector<char>(3)));
        for(int face=0; face<6; face++){
            for(int row=0; row<3; row++){
                for(int col=0; col<3; col++){
                    cube[face][row][col] = getColorLetter(COLOR(face));
                }
            }
        }
    }

    // checking if it is solved or not
    bool isSolved() const override{
        for(int face=0; face<6; face++){
            for(int row=0; row<3; row++){
                for(int col=0; col<3; col++){
                    if(this->cube[face][row][col] != getColorLetter(COLOR(face))) return false;
                }
            }
        }
        return true;
    }

    COLOR getColor(FACE face, int row, int col) const override{
        int ind = static_cast<int>(face);
        char color = cube[ind][row][col];
        switch(color){
            case 'W':
                return COLOR::WHITE;
            case 'G':
                return COLOR::GREEN;
            case 'R':
                return COLOR::RED;
            case 'B':
                return COLOR::BLUE;
            case 'O':
                return COLOR::ORANGE;
            case 'Y':
                return COLOR::YELLOW;
        }
        return COLOR::UNKNOWN;
    }

    void setColor(FACE face, int row, int col, COLOR color) override{
        int ind = static_cast<int>(face);
        cube[ind][row][col] = getColorLetter(color);
    }

    RubiksCube& l() override{
        this->rotateFace(1);

        vector<int> frontStrip(3);
        for(int i=0; i<3; i++){
            frontStrip[i] = cube[2][i][0];
        }

        for(int row=0; row<3; row++){
            // new 1st column of front = 1st column of upper
            cube[2][row][0] = cube[0][row][0];
        }
        for(int row=0; row<3; row++){
            // new 1st column of up = reverse of 3rd column of back
            cube[0][row][0] = cube[4][2-row][2];
        }
        for(int row=0; row<3; row++){
            // new 3rd column of back = reverse of 1st column of down
            cube[4][row][2] = cube[5][2-row][0];
        }
        for(int row=0; row<3; row++){
            // new 1st column of down = 1st column of front
            cube[5][row][0] = frontStrip[row];
        }
        return *this;
    }

    RubiksCube& u() override{
        this->rotateFace(0);

        vector<int> frontStrip(3);
        for(int col=0; col<3; col++){
            frontStrip[col] = cube[2][0][col];
        }
        for(int col=0; col<3; col++){
            // new 1st row of front = 1st row of left
            cube[2][0][col] = cube[1][0][col];
        }
        for(int col=0; col<3; col++){
            // new 1st row of left = 1st row of back
            cube[1][0][col] = cube[4][0][col];
        }
        for(int col=0; col<3; col++){
            // new 1st row of back = 1st row of right
            cube[4][0][col] = cube[3][0][col];
        }
        for(int col=0; col<3; col++){
            // new 1st row of right = 1st row of front
            cube[3][0][col] = frontStrip[col];
        }
        return *this;
    }

    RubiksCube& l_prime() override{
        return *this;
    }

    RubiksCube& l2() override{
        return *this;
    }

    

    RubiksCube& u_prime() override{
        return *this;
    }

    RubiksCube& u2() override{
        return *this;
    }

    RubiksCube& r() override{
        return *this;
    }

    RubiksCube& r_prime() override{
        return *this;
    }

    RubiksCube& r2() override{
        return *this;
    }

    RubiksCube& d() override{
        return *this;
    }

    RubiksCube& d_prime() override{
        return *this;
    }

    RubiksCube& d2() override{
        return *this;
    }

    RubiksCube& b() override{
        return *this;
    }

    RubiksCube& b_prime() override{
        return *this;
    }

    RubiksCube& b2() override{
        return *this;
    }

    RubiksCube& f() override{
        return *this;
    }

    RubiksCube& f_prime() override{
        return *this;
    }

    RubiksCube& f2() override{
        return *this;
    }

};