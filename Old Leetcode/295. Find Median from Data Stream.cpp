#include<iostream>
#include<queue>
using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> lowerHalf; //max_heap
    priority_queue<int, vector<int>, greater<int>> upperHalf; //min_heap
    MedianFinder() 
    {
    }

    void addNum(int num) {
        upperHalf.push(num);
        lowerHalf.push(upperHalf.top());
        upperHalf.pop();
        if (lowerHalf.size() > upperHalf.size())
        {
            upperHalf.push(lowerHalf.top());
            lowerHalf.pop();
        }
    }

    double findMedian() 
    {
        if (lowerHalf.size() == upperHalf.size())
        {
            return ((double)lowerHalf.top() + (double)upperHalf.top()) / 2.0;
        }
        else
        {
            return upperHalf.top();
        }
    }
};

//int main(void)
//{
//    MedianFinder medianFinder;
//    medianFinder.addNum(-1); 
//    cout << medianFinder.findMedian()<<endl;
//    medianFinder.addNum(-2);  
//    cout << medianFinder.findMedian() << endl;
//    medianFinder.addNum(-3);    
//    cout<<medianFinder.findMedian() << endl;
//    medianFinder.addNum(-4);
//    cout << medianFinder.findMedian() << endl;
//    medianFinder.addNum(-5);
//    cout << medianFinder.findMedian() << endl;
//}