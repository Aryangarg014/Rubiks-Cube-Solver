#include<bits/stdc++.h>
using namespace std;

class NibbleArray{

private:
    vector<uint8_t> arr;    // each position stores two 4-bit values(nibbles)
    int size;   // number of 4-bit values
public:
    // initialize the array of a particular size with a particular value
    NibbleArray(int size, uint8_t initialValue=0);
    
    /*
        Sets the value at the corresponding position in the array to the given position of nibble
        pos -> sequential index of the permutation of a Rubik’s cube
        value -> Number of moves it takes to solve the corners of the Rubik’s Cube
    */
    void set(int pos, int value);

    // returns the value stored at the given nibble position
    uint8_t get(int pos) const;

    // returns the number of nibbles stored
    int getSize() const;

    // returns the actual size of the array
    int getStorageSize() const;

    // resets the array with the given value
    void reset(uint8_t value);
};