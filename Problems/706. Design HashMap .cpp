//
// Created by Deepak Sahu on 1/5/22.
//
#include <iostream>
#include <vector>
using namespace std;

class MyHashMap {
    vector<int> hashMap;
public:
    MyHashMap() {
        hashMap.resize(1000000);
    }

    void put(int key, int value)
    {
        hashMap[key] = value;
    }

    int get(int key)
    {
        return hashMap[key];
    }

    void remove(int key) {
        hashMap[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

