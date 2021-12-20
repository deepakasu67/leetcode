#include<iostream>
using namespace std;

class Solution {
public:
    int countLessThanorEqualToMid(int row, int col, int num)
    {
        int count = 0;
        //it will count the num of elements less than num.
        //if last element of row is less than num means we will consider 
        //whole size of 1 row which would be the size of coloumn. 
        // if last element of row is greater than we need to get 
        //which coloumn is less than equal to num
        // we will do this for all the rows.
        for (int i = 1; i <= row; i++)
        {
            count += (row / i, col);
        }
        return count;
    }

    int findKthNumber(int m, int n, int k) 
    {
        int lo = 1, hi = m * n;

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            int count = countLessThanorEqualToMid(m, n, mid);
            if (count > k)
            {
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        return lo;
    }
};

//int main(void)
//{
//
//}