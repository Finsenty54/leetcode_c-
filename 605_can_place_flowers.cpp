#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int l = flowerbed.size();
        /*if (l==1 && flowerbed[0]==0)
        {
            if(n<=1)
                return true;
            else
            {
                return false;
            }
            
        }*/
        
        if (l <=2)
        {
            int sum = (l % 2) + l / 2;
            sum = sum - accumulate(flowerbed.begin(), flowerbed.end(), 0);
            return sum >= n ? true : false;
        }
        int sum = 0;
        if (flowerbed[0] == 0 && flowerbed[1]==0 )
            sum++;
        for (size_t i = 2; i < l-2; i+=2)
        {
            if (flowerbed[i-1]==0 && flowerbed[i]==0 && flowerbed[i+1]==0)
            {
                sum++;
            }
        }
        
        if (flowerbed[l-1]==0 && flowerbed[l-2]==0)
            sum++;

        if(sum>=n)
            return true;
        else
        {
            return false;
        }
        //1 1 2 1 3 2 4 2 5 3 6 3 7 4 8 4 9 5 10 5
    }
};