#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int p1 = m - 1; // nums1 的有效部分指針
        int p2 = n - 1; // nums2 的指針
        int p = m + n - 1; // nums1 的總長度指針
    
        // 從後往前合併
        while (p1 >= 0 && p2 >= 0)
        {
            if (nums1[p1] > nums2[p2])
            {
                nums1[p] = nums1[p1];
                p1--;
            }
            else
            {
                nums1[p] = nums2[p2];
                p2--;
            }
            p--;
        }

        // 如果 nums2 還有剩餘元素，填入 nums1
        while (p2 >= 0)
        {
            nums1[p] = nums2[p2];
            p2--;
            p--;
        }
    
        // 不需要額外處理 nums1 剩餘的部分，因為它們已經在正確位置。
    }
};

int main()
{
    Solution Sol;
    // Test case
    // nums1.size() = m + n
    // nums2.size() = n
    // 0 <= m <= 200
    // 0 <= n <= 200
    // 1 <= m + n <= 200
    // -10^9 <= nums1[index] <= 10^9
    // -10^9 <= nums2[index] <= 10^9
    vector<int> nums1 = {1, 2, 3, 0, 0, 0}; // nums1 has space for nums2
    int m = 3; // Number of actual elements in nums1
    vector<int> nums2 = {2, 5, 6};
    int n = 3; // Number of elements in nums2

    // Call the merge function
    Sol.merge(nums1, m, nums2, n);

    // Print the merged array
    cout << "Merged array: ";
    for (int num : nums1)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}