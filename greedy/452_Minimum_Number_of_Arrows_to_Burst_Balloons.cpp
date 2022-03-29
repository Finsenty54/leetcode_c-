#include<iostream>
#include<numeric>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty())
        {
            return 0;
        }
        sort(points.begin(),points.end(),[](vector<int> a,vector<int> b){
            return a[1]<b[1];
        });
        int n=points.size();
        int end=points[0][1],begin=points[0][0];
        vector<int> total(n,1);
        for (size_t i = 1; i < n; i++)
        {
            if (points[i][0]<=end )
            {
                total[i]=0;
            }
            else
            {
                end=points[i][1];
            }
        }
        return accumulate(total.begin(),total.end(),0);
        
        
    }
};

int main()
{
    vector<vector<int>> test={{1,9},{7,16},{2,5},{7,12},{9,11},{2,10},{9,16},{3,9},{1,3}};
    Solution t;
    cout<<t.findMinArrowShots(test);

}