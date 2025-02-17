#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    // nums1 is a subset of nums2
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        // input a interger, output also a interger, and set a unordered_map named hash.
        unordered_map<int, int> hash;
        vector<int> res;
        for (int n: nums2) { // for n in nums2
            while (!stk.empty() && stk.top() < n) {
                // hash is a map relation, it can also be a dictionary structure
                hash[stk.top()] = n;
                stk.pop();
            }
            stk.push(n); // Push n in nums2 first
        }

        for (int n: nums1) {
            // cout << hash[n] << endl;
            // if n as a key and n in hash, return hash[n] in res
            // if not, return -1
            // VectorName.push_back(condition? true:false);
            res.push_back(hash.count(n)? hash[n]:-1);
        }
        return res;
    }
};

int main()
{
    Solution Sol;
    // Test case
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    // Correct function call
    vector<int> nextGreater = Sol.nextGreaterElement(nums1, nums2);

    // Print the result
    for (int element : nextGreater)
    {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}