#include<iostream>
#include<unordered_map>
#include<utility>
using namespace std;

class LRUCache {
public:
    int  _capacity;
    list<pair<int,int>> cache;
    unordered_map<int, list<pair<int,int>>::iterator > keyToCacheElts;
    LRUCache(int capacity) 
    {
        _capacity = capacity;
    }
    void insertAtfront(int key, int value)
    {
        auto it = keyToCacheElts.find(key);

        cache.erase(it->second);
        auto newIt = cache.insert(cache.begin(), make_pair(key,value));
        keyToCacheElts[key] = newIt;
    }
    int get(int key) 
    {
        if (keyToCacheElts.find(key) == keyToCacheElts.end())
            return -1;
        insertAtfront(key, keyToCacheElts[key]->second);
        list<pair<int, int>>::iterator it = keyToCacheElts[key];

        return it->second;
    }

    void put(int key, int value) 
    {
        // 1. if key is already there then put it infront of the list;
        if (keyToCacheElts.find(key) != keyToCacheElts.end())
        {
            insertAtfront(key, value);
        }
        else
        {
            if (keyToCacheElts.size() == _capacity)
            {
                //1. evict the LRU items then insert at the begin of list
                keyToCacheElts.erase(cache.back().first);
                cache.pop_back();

                //2. insert new element at the front;
                auto it = cache.insert(cache.begin(), make_pair(key, value));
                keyToCacheElts[key] = it;
            }
            else
            {
                auto it = cache.insert(cache.begin(), make_pair(key, value));
                keyToCacheElts[key] = it;
            }

        }
    }
};

//int main(void)
//{
//    LRUCache lru(2);
//    //lru.put(1, 1); // cache is {1=1}
//    //lru.put(2, 2); // cache is {1=1, 2=2}
//    //cout<<lru.get(1)<<endl;    // return 1
//    //lru.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
//    //cout<<lru.get(2) << endl;    // returns -1 (not found)
//    //lru.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
//    //cout<<lru.get(1) << endl;    // return -1 (not found)
//    //cout<<lru.get(3) << endl;    // return 3
//    //cout<<lru.get(4) << endl;    // return 4
//    lru.put(2, 1);
//    lru.put(2, 2);
//    cout<<lru.get(2);
//    lru.put(1, 1);
//    lru.put(4, 1);
//    cout<<lru.get(2);
//}