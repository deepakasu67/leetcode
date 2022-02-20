//
// Created by Deepak Sahu on 2/5/22.
//
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Bitset {
    bool *bitSetStorage;
    bool *flipBitSetStorage;
    int setBit = 0;
    int size = 0;
public:
    Bitset(int size) {
        bitSetStorage = new bool[size]();
        flipBitSetStorage = new bool[size]();
        this->size = size;
    }


    void fix(int idx) {
        if (bitSetStorage[idx] == false) {
            bitSetStorage[idx] = true;
            flipBitSetStorage[idx] = false;
            setBit++;
        }

    }

    void unfix(int idx) {
        if (bitSetStorage[idx] == true) {
            bitSetStorage[idx] = false;
            flipBitSetStorage[idx] = true;
            setBit--;
        }
    }

    void flip() {
        bool *temp = bitSetStorage;
        bitSetStorage = flipBitSetStorage;
        flipBitSetStorage = temp;
        setBit = size - setBit;
    }

    bool all() {
        return setBit == this->size;
    }

    bool one() {
        return setBit;
    }

    int count() {
        return setBit;
    }

    string toString() {
        string result;
        for (int i = 0; i < size; i++) {
            if (bitSetStorage[i] == true) {
                result.push_back('1');
            } else
                result.push_back('0');
        }
        return result;
    }
};