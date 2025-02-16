#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeElement(vector<int>& nums, int val)
    {
        int i = 0; // 指向下個要放置非 val 元素的位置
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] != val)
            {
                nums[i] = nums[j]; // 將非 val 元素移動到前部
                i++;
            }
        }
        return i; // 返回新長度
    }
};

int main()
{
    Solution Sol;
    // Test case
    // 0 <= nums.size() <= 100
    // 0 <= nums[index] <= 50
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    // 0 <= val <= 100
    int val = 2;
    // Note that all the elements can be returned in any order
    int removeElement = Sol.removeElement(nums, val);

    for(int element : nums)
    {
        cout << element << " ";
    }
    cout << endl;
    cout << removeElement << endl;

    return 0;
}