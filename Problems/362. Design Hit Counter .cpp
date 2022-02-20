//
// Created by Deepak Sahu on 1/7/22.
//

#include <iostream>
#include <map>
using namespace std;

class HitCounter {
    int sum = 0;
    map<int, int> hitCounter;
public:
    HitCounter() {

    }

    void hit(int timestamp)
    {
        hitCounter[timestamp] = ++sum;
    }

    int getHits(int timestamp)
    {
        int fiveMinBefore = timestamp - 300;
        if(fiveMinBefore <= 0)
        {
            return hitCounter.rbegin()->second;
        }
        auto it = prev(hitCounter.upper_bound(fiveMinBefore));
        return hitCounter.rbegin()->second - it->second;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
