#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<vector<int>> trustedBy(N);
        int trustSize = trust.size();
        vector<int> vi;
        for (auto const& trustLink : trust)
        {
            trustedBy[trustLink[1] - 1].push_back(trustLink[0] - 1);
        }
        auto judge = find_if(begin(trustedBy), end(trustedBy), [N](auto trustedList)
                                                            {
                                                                if (trustedList.size() == N - 1)
                                                                    return true;
                                                                else
                                                                    return false;
                                                            });
        if (judge != trustedBy.end())
        {
            int probableJudge = (judge - trustedBy.begin());
            auto confirmJudge = find_if(begin(trustedBy), end(trustedBy), [probableJudge](vector<int> trustedList)
                                                                                         {
                                                                                            if (find(begin(trustedList), end(trustedList), probableJudge) != trustedList.end())
                                                                                                return true;
                                                                                            else
                                                                                                return false;
                                                                                         });
            if (confirmJudge == trustedBy.end())
                return probableJudge + 1;
            else
                return -1;
        }
        else
        {
            return -1;
        }
    }
};
//int main(void)
//{
//    Solution obj;
//    vector<vector<int>> trust = { {1,3},
//                                  {1,4},
//                                  {2,3},
//                                  {2,4},
//                                  {4,3}
//                                };
//    cout<<obj.findJudge(4,trust);
//}