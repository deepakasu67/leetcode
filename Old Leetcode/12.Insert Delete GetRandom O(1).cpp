#include<iostream>
#include<unordered_set>
#include<iterator>
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 

using namespace std;
class RandomizedSet {
    unordered_set<int> set;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        fastIO
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (set.find(val) == set.end())
        {
            set.insert(val);
            return true;
        }
        return false;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (set.find(val) != set.end())
        {
            set.erase(val);
            return true;
        }
        return false;
    }

    /** Get a random element from the set. */
    int getRandom() {
        int n = rand() % set.size();
        auto it = set.begin();
        advance(it , n);
        return *it;
    }
};
