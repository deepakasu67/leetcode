#include<iostream>
#include<vector>
using namespace std;
//
//class Solution {
//public:
//    int longestMountain(vector<int>& A)
//    {
//        vector<pair<int, int>> climbUpIndices;
//        int longestMountain = 0;
//        bool itsIncreasing = false;
//        for(int i =0 ; i < A.size() - 1; i++)
//        {
//            if(A[i + 1] - A[i] > 0 && itsIncreasing == false)
//            {
//                climbUpIndices.emplace_back(make_pair(i, i + 1));
//                itsIncreasing = true;
//                continue;
//            }
//            if(itsIncreasing == true)
//            {
//                climbUpIndices.back().second = i;
//            }
//            if(A[i + 1] - A[i] <= 0)
//            {
//                itsIncreasing = false;
//            }
//        }
//        if (climbUpIndices.empty())
//            return longestMountain;
//
//        if(climbUpIndices.back().second + 1 == A.size() - 1)
//        {
//            if(A[A.size() -1] - A[climbUpIndices.back().second] >= 0)
//            {
//                climbUpIndices.back().second = A.size() - 1;
//            }
//        }
//        for(int i =0;i < climbUpIndices.size();i++)
//        {
//            int startIdx = climbUpIndices[i].second;
//            int endIdx =  i < climbUpIndices.size() - 1 ? climbUpIndices[i + 1].first : A.size() - 1;
//            int climbDownIdx = -1;
//            if(A.size() -1 == startIdx)
//                continue;
//            for(;startIdx < endIdx;startIdx++)
//            {
//                if(A[startIdx + 1] - A[startIdx] >= 0)
//                {
//                    break;
//                }
//                else
//                {
//                    climbDownIdx = startIdx;
//                }
//            }
//            if(climbDownIdx == -1)
//                continue;
//            longestMountain = max(longestMountain, (startIdx - climbUpIndices[i].first) + 1);
//        }
//        return longestMountain;
//    }
//};

class Solution {
public:
    int longestMountain(vector<int>& A) {
        int maxlen = 0;
        int n = A.size();
        if (n < 3) return 0;

        for (int i = 1; i < n - 1; i++) {
            if (A[i - 1]<A[i] && A[i] > A[i + 1]) {
                int left = i - 1;
                int right = i + 1;

                while (left > 0 and A[left - 1] < A[left])
                    left--;
                while (right < n - 1 and A[right + 1] < A[right])
                    right++;

                maxlen = max(maxlen, right - left + 1);
            }
        }
        return maxlen;
    }
};

//int main(void)
//{
//    vector<int> vec = {0, 1,0};
//    Solution obj;
//    obj.longestMountain(vec);
//}