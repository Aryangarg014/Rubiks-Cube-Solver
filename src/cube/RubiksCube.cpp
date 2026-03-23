#include <bits/stdc++.h>

#include "RubiksCube.h"
using namespace std;

char RubiksCube::getColorLetter(COLOR color){
    switch(color){
        case COLOR::RED :
            return 'R';
        case COLOR::BLUE :
            return 'B';
        case COLOR::GREEN :
            return 'G';
        case COLOR::YELLOW :
            return 'Y';
        case COLOR::ORANGE :
            return 'O';
        case COLOR::WHITE :
            return 'W';
        default:
            return '?';
    }
}

void RubiksCube::print() const{
    cout << "Rubiks Cube : " << endl << endl;

    for(int row=0; row<3; row++){
        for (int i=0; i<7; i++) cout << " ";

        for(int col=0; col<3; col++){
            cout << getColorLetter(getColor(FACE::UP, row, col)) << " ";
        }
        cout << endl;
    }
    cout << endl;

    for(int row=0; row<3; row++){
        for(int col=0; col<3; col++){
            cout << getColorLetter(getColor(FACE::LEFT, row, col)) << " ";
        }
        cout << " ";
        for(int col=0; col<3; col++){
            cout << getColorLetter(getColor(FACE::FRONT, row, col)) << " ";
        }
        cout << " ";
        for(int col=0; col<3; col++){
            cout << getColorLetter(getColor(FACE::RIGHT, row, col)) << " ";
        }
        cout << " ";
        for(int col=0; col<3; col++){
            cout << getColorLetter(getColor(FACE::BACK, row, col)) << " ";
        }
        cout << endl;
    }
    cout << endl;

    for(int row=0; row<3; row++){
        for (int i=0; i<7; i++) cout << " ";

        for(int col=0; col<3; col++){
            cout << getColorLetter(getColor(FACE::DOWN, row, col)) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

vector<RubiksCube::MOVE> RubiksCube::randomShuffleRubiksCube(int n){
    vector<MOVE> moves;

    for(int i=0; i<n; i++){
        int ind = rand() % 18;
        MOVE randomMove = static_cast<MOVE>(ind);
        moves.push_back(randomMove);
        this->move(randomMove);
    }
    return moves;
}

RubiksCube& RubiksCube::move(MOVE m){
    switch(m){
        case MOVE::L : 
            return this->l();
        case MOVE::L_PRIME :
            return this->l_prime();
        case MOVE::L2:
            return this->l2();
        case MOVE::R:
            return this->r();
        case MOVE::R_PRIME:
            return this->r_prime();
        case MOVE::R2:
            return this->r2();
        case MOVE::U:
            return this->u();
        case MOVE::U_PRIME:
            return this->u_prime();
        case MOVE::U2:
            return this->u2();
        case MOVE::D:
            return this->d();
        case MOVE::D_PRIME:
            return this->d_prime();
        case MOVE::D2:
            return this->d2();
        case MOVE::F:
            return this->f();
        case MOVE::F_PRIME:
            return this->f_prime();
        case MOVE::F2:
            return this->f2();
        case MOVE::B:
            return this->b();
        case MOVE::B_PRIME:
            return this->b_prime();
        case MOVE::B2:
            return this->b2();
        default:
            return *this;
    }
}

RubiksCube& RubiksCube::invert(MOVE m){
    switch(m){
        case MOVE::L : 
            return this->l_prime();
        case MOVE::L_PRIME :
            return this->l();
        case MOVE::L2:
            return this->l2();
        case MOVE::R:
            return this->r_prime();
        case MOVE::R_PRIME:
            return this->r();
        case MOVE::R2:
            return this->r2();
        case MOVE::U:
            return this->u_prime();
        case MOVE::U_PRIME:
            return this->u();
        case MOVE::U2:
            return this->u2();
        case MOVE::D:
            return this->d_prime();
        case MOVE::D_PRIME:
            return this->d();
        case MOVE::D2:
            return this->d2();
        case MOVE::F:
            return this->f_prime();
        case MOVE::F_PRIME:
            return this->f();
        case MOVE::F2:
            return this->f2();
        case MOVE::B:
            return this->b_prime();
        case MOVE::B_PRIME:
            return this->b();
        case MOVE::B2:
            return this->b2();
        default:
            return *this;
    }
}

string RubiksCube::getMove(MOVE move){
    switch (move) {
        case MOVE::L:
            return "L";
        case MOVE::L_PRIME:
            return "L'";
        case MOVE::L2:
            return "L2";
        case MOVE::R:
            return "R";
        case MOVE::R_PRIME:
            return "R'";
        case MOVE::R2:
            return "R2";
        case MOVE::U:
            return "U";
        case MOVE::U_PRIME:
            return "U'";
        case MOVE::U2:
            return "U2";
        case MOVE::D:
            return "D";
        case MOVE::D_PRIME:
            return "D'";
        case MOVE::D2:
            return "D2";
        case MOVE::F:
            return "F";
        case MOVE::F_PRIME:
            return "F'";
        case MOVE::F2:
            return "F2";
        case MOVE::B:
            return "B";
        case MOVE::B_PRIME:
            return "B'";
        case MOVE::B2:
            return "B2";
    }
}