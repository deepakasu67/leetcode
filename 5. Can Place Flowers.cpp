#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n)
    {
        if(flowerbed.size() < n)
        {
            return false;
        }
        for(int i =0; i < flowerbed.size() && n;)
        {
            if(flowerbed[i] == 1)
            {
                i += 2;
            }
            else
            {
                if(i > 0 && flowerbed[i-1] == 0)
                {
                    if(i < flowerbed.size() - 1 && flowerbed[i+1] == 0 )
                    {
                        n--;
                        i += 2;
                        continue;
                    }
                    if(i == flowerbed.size() - 1 && flowerbed[i-1] ==0)
                    {
                        n--;
                        i += 2;
                        continue;
                    }
                }
                if(i == 0 )
                {
                    if(flowerbed.size() > 1 )
                    {
                        if(flowerbed[i + 1] == 0)
                        {
                            n--;
                            i += 2;
                            continue;
                        }
                    }
                    else if(flowerbed.size() == 1)
                    {
                        n--;
                        i += 2;
                        continue;
                    }
                    
                }

                i++;
            }
        }
        return n ? false : true;
    }
};

//int main(void)
//{
//    Solution obj;
//    vector<int> flowerBed = { 0,0,1,0,1 };
//    cout<<obj.canPlaceFlowers(flowerBed, 1);
//}