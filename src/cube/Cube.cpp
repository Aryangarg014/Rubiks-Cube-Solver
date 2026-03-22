#include <Cube.h>
#include <bits/stdc++.h>

using namespace std;

char Cube::getColorLetter(COLOR color){
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
    }
}

void Cube::print() const{
    cout << "Rubiks Cube : " << endl << endl;

    for(int row=0; row<3; row++){
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
        for(int col=0; col<3; col++){
            cout << getColorLetter(getColor(FACE::DOWN, row, col)) << " ";
        }
        cout << endl;
    }
}

vector<Cube::MOVE> Cube::randomShuffleCube(int n){

}

Cube& Cube::move(MOVE m){
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
    }
}

Cube& Cube::invert(MOVE m){
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
    }
}