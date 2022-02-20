//
// Created by Deepak Sahu on 1/2/22.
//
#include <iostream>
#include <vector>
using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
   // Return true if this NestedInteger holds a single integer, rather than a nested list.
   bool isInteger() const;

   // Return the single integer that this NestedInteger holds, if it holds a single integer
   // The result is undefined if this NestedInteger holds a nested list
   int getInteger() const;

   // Return the nested list that this NestedInteger holds, if it holds a nested list
   // The result is undefined if this NestedInteger holds a single integer
   const vector<NestedInteger> &getList() const;
};

class NestedIterator {
    vector<int> list;
    int currIdx = 0;
public:
    void FlattenNestedInt(const vector<NestedInteger>& nestedList)
    {
        for(int i =0;i < nestedList.size(); i++)
        {
            if(nestedList[i].isInteger()) {
                list.push_back(nestedList[i].getInteger());
            }
            else
            {
                FlattenNestedInt(nestedList[i].getList());
            }
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
        FlattenNestedInt(nestedList);
    }

    int next() {
        return list[currIdx];
    }

    bool hasNext() {
        return ++currIdx < list.size() ?  true : false;
    }
};


