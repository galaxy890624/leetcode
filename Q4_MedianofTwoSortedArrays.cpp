#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> MergedArray;
        // initialize PtrLeft, PtrRight
        int PtrLeft = 0;
        int PtrRight = nums1.size() + nums2.size() -1; // last element index in MergedArray
        float ans;
        // insert all the elements of nums1 into MergedArray
        for(int index = 0; index < nums1.size(); index++)
        {
            MergedArray.push_back(nums1[index]);
        }
        // insert all the elements of nums2 into MergedArray
        for(int index = 0; index < nums2.size(); index++)
        {
            MergedArray.push_back(nums2[index]);
        }
        // it may occur this condition below,so we need to sort 
        // nums1 = [0, 2, 4]
        // nums2 = [3, 5, 6, 7]
        sort(MergedArray.begin(), MergedArray.end());
        while(PtrLeft < PtrRight)
        {
            PtrLeft++;
            PtrRight--;
        }
        // no matter what MergedArray.size() is even or odd,
        // the answer is ( MergedArray[PtrLeft] + MergedArray[PtrRight] ) / 2.0
        ans = ( MergedArray[PtrLeft] + MergedArray[PtrRight] ) / 2.0;
        return ans;
    }
};

int main()
{
    Solution Sol;
    
    // Test case
    vector<int> nums1 = {0, 2, 4}; // 0 <= nums1.size() <= 1000
    vector<int> nums2 = {3, 5, 6, 7}; // 0 <= nums2.size() <= 1000
    double ans = Sol.findMedianSortedArrays(nums1, nums2);
    
    cout << ans << endl;

    return 0;
}