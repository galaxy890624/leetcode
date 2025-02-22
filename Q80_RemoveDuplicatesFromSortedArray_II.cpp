#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        if (nums.size() <= 2) return nums.size(); // If array is small, no need to modify
        
        int left = 1; // Slow pointer (index where next valid element is placed)
        int count = 1; // Track occurrences of the current number

        for (int right = 1; right < nums.size(); right++)
        {
            if (nums[right] == nums[right - 1]) // If it's a duplicate
            {
                count++; // Increase count
            }
            else
            {
                count = 1; // Reset count for a new number
            }

            if (count <= 2) // Allow up to two occurrences
            {
                nums[left] = nums[right];
                left++; // Move slow pointer
            }
        }

        return left; // New array length
    }
};

int main()
{
    Solution Sol;
    vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 3}; // Expected result: {0, 0, 1, 1, 2, 3, 3}
    
    int newLength = Sol.removeDuplicates(nums);

    cout << "Modified array: ";
    for (int i = 0; i < newLength; i++) // Print only the modified part
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    
    cout << "New length = " << newLength << endl;

    return 0;
}