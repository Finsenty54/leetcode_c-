#include<iostream>
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
        int total,prev=points[0][1];
        
    }
};