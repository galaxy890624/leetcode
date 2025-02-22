#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        // unordered_map <key's data type, value's data type> name
        unordered_map<int, int> hash;
        vector<int> ans;
        for (int index = 0; index < nums.size(); index++)
        {
            // if you can find out nums[index] in hash, return 1
            // else, return 0
            if (hash.count(nums[index]))
            {
                // add a new element hash[nums[index]] at the end of ans
                ans.push_back(hash[nums[index]]);
                ans.push_back(index);
                break;
            }
            hash[target - nums[index]] = index;
        }
        return ans;
    }
};

int main()
{
    Solution Sol;
    // Test case
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> ans = Sol.twoSum(nums, target);
    
    if (!ans.empty())
    {
        cout << "Indices: ";
        for (int index : ans)
        {
            cout << index << " ";
        }
        cout << endl;
    }
    else {
        cout << "No solution found!" << endl;
    }

    return 0;
}