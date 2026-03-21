#pragma once
#include<bits/stdc++.h>
using namespace std;

class Cube{

public:
    enum class FACE{
        UP, LEFT, FRONT, RIGHT, BACK, DOWN
    };

    enum class MOVE{
        U, U_PRIME, U2,
        L, L_PRIME, L2,
        F, F_PRIME, F2,
        R, R_PRIME, R2,
        B, B_PRIME, B2,
        D, D_PRIME, D2
    };

    enum class COLOR{
        RED, BLUE, GREEN, YELLOW, ORANGE, WHITE
    };
    

    // returns if the rubiks cube is solved or not
    virtual bool isSolved() const = 0;


    // print function (planar representation)
    void print() const;

    /*
     * Print the Rubik Cube in Planar format.
     *
     * The cube is opened as follows.
     *
     * The sides:
     *    U
     *  L F R B
     *    D
     *
     * Color wise:
     *
     *          W W W
     *          W W W
     *          W W W
     *
     *  G G G   R R R   B B B   O O O
     *  G G G   R R R   B B B   O O O
     *  G G G   R R R   B B B   O O O
     *
     *          Y Y Y
     *          Y Y Y
     *          Y Y Y
    */


    // randomly shuffle a solved cube n number of times
    vector<MOVE> randomShuffleCube(int n);


    // tells color of a particular cell given the face, row, col
    virtual COLOR getColor(FACE face, int row, int col) const = 0;


    // sets color of a particular cell given the face, row, col to the given color
    virtual void setColor(FACE face, int row, int col, COLOR color) = 0;

    
    // Returns the first letter of the given COLOR
    static char getColorLetter(COLOR color);


    // makes a particular move and then return the same Cube object
    Cube& move(MOVE m);


    Cube& invert(MOVE m);

    // specific functions for moves
    virtual Cube& l() = 0;

    virtual Cube& l_prime() = 0;

    virtual Cube& l2() = 0;

    virtual Cube& u() = 0;

    virtual Cube& u_prime() = 0;

    virtual Cube& u2() = 0;

    virtual Cube& r() = 0;

    virtual Cube& r_prime() = 0;

    virtual Cube& r2() = 0;

    virtual Cube& d() = 0;

    virtual Cube& d_prime() = 0;

    virtual Cube& d2() = 0;

    virtual Cube& b() = 0;

    virtual Cube& b_prime() = 0;

    virtual Cube& b2() = 0;

    virtual Cube& f() = 0;

    virtual Cube& f_prime() = 0;

    virtual Cube& f2() = 0;

};