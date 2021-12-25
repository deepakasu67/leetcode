#include<iostream>
#include<vector>
using namespace std;
class MyHashSet {
    vector<bool> hash;
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        hash.resize(1000000,false);
    }

    void add(int key) {
        hash[key] = true;
    }

    void remove(int key) {
        hash[key] = false;
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return hash[key];
    }
};
//int main(void)
//{
//
//}