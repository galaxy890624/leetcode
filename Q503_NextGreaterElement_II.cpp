#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int>& nums)
    {
        stack<int> stk;
        // input a interger, output also a interger, and set a unordered_map named hash.
        unordered_map<int, int> hash;
        // all of elements is set -1
        vector<int> res(nums.size(), -1);
        // FindNextGreater
        for(int i = 0; i < 2 * nums.size(); ++i)
        {
            int num = nums[i % nums.size()];
            while(!stk.empty() && num > nums[stk.top()])
            {
                int index = stk.top();
                stk.pop();
                // hash is a map relation, it can also be a dictionary structure
                hash[nums[index]] = num;
                res[index] = num;
            }
            // to avoid handle repeatly, you need to push index when it traverse first time
            if (i < nums.size())
            {
                stk.push(i);
            }
        }
        return res;
    }
};

int main()
{
    Solution Sol;
    // Test case
    // 1 <= nums.size() <= 10^4
    // -10^9 <= nums[index] <= 10^9
    vector<int> nums = {1, 2, 3, 4, 3};
    vector<int> result = Sol.nextGreaterElements(nums);
    for(int element : result)
    {
        cout << element << " ";
    }
    cout << endl;
    
    return 0;
}