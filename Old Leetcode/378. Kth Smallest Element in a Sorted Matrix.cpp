#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct comparator
{
    int  operator()(const vector<int>& a, const vector<int>& b) const
    {
        return a[0] > b[0];
    }
};
class Solution {
public:

    int kthSmallest(vector<vector<int>>& matrix, int k)
    {
        priority_queue < vector<int>, vector<vector<int>>,  comparator> minHeap;
        int row1 = matrix.size();

        for(int row  =0; row< min(k,row1); row++)
        {
            vector<int> temp = { matrix[row][0],row, 0 };
            minHeap.push(temp);
        }

        while(k -1 > 0)
        {
            vector<int> minEle = minHeap.top();
            int ele = minEle[0];
            int row = minEle[1];
            int col = minEle[2];

            minHeap.pop();
            k--;

            if(col < matrix[0].size() - 1)
            {
                vector<int> temp = { matrix[row][col+1], row, col + 1 };
                minHeap.push(temp);
            }
        }
        return minHeap.top()[0];
    }
};

//int main(void)
//{
//    vector<vector<int>> matrix = { {1, 5, 9},{10, 11, 13},{12, 13, 15}};
//    int k = 8;
//    Solution obj;
//    cout<<obj.kthSmallest(matrix, k);
//}
