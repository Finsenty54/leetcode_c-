#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;

using ll= long long;
class Solution {
public:
    bool judgeSquareSum(int c) {
        unsigned end=sqrt(c); //是开根，而不是简单的除以2
        unsigned begin=0;
         while(begin <= end)
        {
            long re=begin*begin+end*end;
            if (re==c)
            {
                return true;
            }
            else if (re>c)
            {
                --end;
            }
            else
            {
                ++begin;
            }
        }
        return false;
    }
};