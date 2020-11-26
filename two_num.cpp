#include <vector>
#include <iostream>
using namespace std;

class two_num
{
private:

public:
    vector<int> twoSum(vector<int> &nums, int target);
};

vector<int> two_num::twoSum(vector<int> &nums, int target)
{
    int q = 0, p = 0;

    for (size_t i = 0; i < nums.size(); i++)
    {
        int tmp = target - nums[i];
        p = i;
        for (size_t j = i + 1; j < nums.size(); j++)
        {
            if (tmp - nums[j] == 0)
            {
                q = j;
                vector<int> exam;
                exam.push_back(p);
                exam.push_back(q);
                return exam;
            }
        }

    }
    vector<int> nu;
    return nu;
}

int main()
{
    two_num t;
    vector<int> ex;
    ex.push_back(3);
    ex.push_back(2);
    ex.push_back(4);

    vector<int> re = t.twoSum(ex, 6);
    for (int i = 0; i < re.size(); i++)
    {
        cout << re.at(i) << endl;
    }

    return 0;
}