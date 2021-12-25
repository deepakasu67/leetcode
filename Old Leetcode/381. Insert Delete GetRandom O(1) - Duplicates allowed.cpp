#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class RandomizedCollection {
    vector<int> num;
    unordered_map<int, unordered_set<int>> numToIndices;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {

    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val)
    {
        bool returningval = true;
        if(numToIndices.find(val) != numToIndices.end())
        {
            returningval =  false;
        }
        num.emplace_back(val);
        numToIndices[val].insert(num.size() - 1);
        return returningval;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val)
    {
        auto it = numToIndices.find(val);
        if(it == numToIndices.end())
        {
            return false;
        }
        auto free_pos = *it->second.begin();
        numToIndices.find(val)->second.erase(*it->second.begin());
        num[free_pos] = num.back();
        numToIndices[num.back()].insert(free_pos);
        numToIndices[num.back()].erase(num.size() - 1);
        if (numToIndices.find(val)->second.empty())
            numToIndices.erase(val);
        num.pop_back();
        return true;
    }

    /** Get a random element from the collection. */
    int getRandom()
    {
        return num[rand() % num.size()];
    }
};

//int main(void)
//{
//    RandomizedCollection* obj = new RandomizedCollection();
//    cout<< obj->insert(10) << endl;
//    cout << obj->insert(10) << endl;
//    cout << obj->insert(20) << endl;
//    cout << obj->insert(20) << endl;
//    cout << obj->insert(30) << endl;
//    cout << obj->insert(30) << endl;
//
//    cout<< obj->remove(10) << endl;
//    cout<< obj->remove(20) << endl;
//    cout<< obj->remove(20) << endl;
//    cout<< obj->remove(10) << endl;
//    cout<< obj->remove(30) << endl;
//    cout << obj->insert(40) << endl;
//    cout << obj->remove(30) << endl;
//    cout << obj->remove(30) << endl;
//
//    cout << obj->getRandom() << endl;
//    cout << obj->getRandom() << endl;
//    cout << obj->getRandom() << endl;
//    cout << obj->getRandom() << endl;
//    cout << obj->getRandom() << endl;
//    cout << obj->getRandom() << endl;
//    cout << obj->getRandom() << endl;
//    cout << obj->getRandom() << endl;
//    cout << obj->getRandom() << endl;
//    cout << obj->getRandom() << endl;
//
//}