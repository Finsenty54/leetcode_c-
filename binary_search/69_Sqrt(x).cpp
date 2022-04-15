#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int be=0,middle=x/2,end=x;
        while (true)
        {
            if ((middle*middle) >x)
            {
                end=middle;
            }
            else if((middle*middle) < x)
            {
                if (((middle+1)*(middle+1))>x)
                {
                    return middle;
                }
                else if((middle+1)*(middle+1)==x)
                {
                    return middle+1;
                }
                
                be=middle;
            }
            else
            {
                return middle;
            }
            middle=(be+end)/2;
        }
        
    }
};