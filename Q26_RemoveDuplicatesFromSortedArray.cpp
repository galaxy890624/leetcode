#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        if (nums.empty())
        {
            return 0; // 處理空數組情況
        }
        
        int ptr1 = 0; // 標記唯一元素的位置
        for (int ptr2 = 1; ptr2 < nums.size(); ptr2++)
        {
            if (nums[ptr1] != nums[ptr2]) // 發現新元素
            {
                ptr1++; // 移動標記位置
                nums[ptr1] = nums[ptr2]; // 覆蓋唯一元素的位置
            }
        }
        return ptr1 + 1; // 返回新數組的長度
    }
};

int main()
{
    Solution Sol;
    // Test case
    // 1 <= nums.size() <= 3 * 10^4
    // -100 <= nums[index] <= 100
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int removeDuplicates = Sol.removeDuplicates(nums);

    for(int element : nums)
    {
        cout << element << " ";
    }
    cout << endl;
    cout << "removeDuplicates = " << removeDuplicates << endl;

    return 0;
}