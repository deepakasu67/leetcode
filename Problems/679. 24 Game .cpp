//
// Created by Deepak Sahu on 1/12/22.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
 bool judgePoint24(vector<int> cards) {
        vector<double> in;

        for(int i : cards){
            in.push_back((double)i);
        }

        return dfs(in);
    }


 bool dfs(vector<double> cards){
        if(cards.size()==1){
            if(abs(cards.at(0)-24.0)<0.001) return true;
            return false;
        }

        for(int i=0;i<cards.size();i++){
            for(int j=i+1;j<cards.size();j++){
                vector<double> next;

                for(int k=0;k<cards.size();k++){
                    if(k!=i && k!=j) next.push_back(cards.at(k));
                }

                vector<double> possibleCombinations=generatePossibleResults(cards.at(i),cards.at(j));
                for(double c:possibleCombinations){
                    next.push_back(c);
                    if(dfs(next))
                        return true;
                    next.pop_back();
                }

            }
        }
        return false;
    }

     vector<double> generatePossibleResults(double a, double b) {
        vector<double> res;
        res.push_back(a + b);
        res.push_back(a - b);
        res.push_back(b - a);
        res.push_back(a * b);
        res.push_back(a / b);
        res.push_back(b / a);
        return res;
    }
};
//int main(void)
//{
//    vector<int> cards = {4,1,8,7};
//    cout<<Solution().judgePoint24(cards);
//}