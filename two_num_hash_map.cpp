#include<unordered_map>
#include<iostream>
#include<vector>
using namespace std;
class two_num_hash_map
{
private:
    /* data */
public:
    vector<int> two_num(vector<int> nums,int target);
};

vector<int> two_num_hash_map::two_num(vector<int> nums,int target){
    unordered_map<int,int> mymap;
    vector<int> rec;
    for (size_t i = 0; i < nums.size(); i++)
    {
        int t=target-nums[i];
        if (mymap.count(t) && mymap[t]!=i)
        {
            rec.push_back(i);
            rec.push_back(mymap[t]);
            return rec;
        }
        mymap.insert(make_pair(nums[i],i));   
    }
    return rec;
}

int main()
{
    two_num_hash_map t;
    vector<int> ex;
    ex.push_back(3);
    ex.push_back(2);
    ex.push_back(4);

    vector<int> re = t.two_num(ex, 6);
    for (int i = 0; i < re.size(); i++)
    {
        cout << re.at(i) << endl;
    }

    return 0;
}

