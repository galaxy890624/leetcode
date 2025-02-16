#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int>& digits)
    {
        vector<int> Ans;
        // +1
        digits[digits.size() - 1]++;
        // carry
        for (int index = digits.size() - 1; index >= 0; index--)
        {
            // If >=10, then digits[index - 1] +1
            // Example: digits = {3, 17, 5, 40} -> {3, 17, 9, 0} -> {4, 7, 9, 0}
            // Example: digits = {9, 9, 9, 10} -> {9, 9, 10, 0} -> {9, 10, 0, 0} -> {10, 0, 0, 0} -> {1, 0, 0, 0, 0}
            if (digits[index] >= 10)
            {
                // If digits[index] = 78, then carry = 7
                int carry = digits[index] / 10;
                // Reserve units digit
                digits[index] %= 10;
                if (index > 0)
                {
                    digits[index - 1] += carry;
                }
                // If all the elements of digits is 0, then digits.insert(digits.begin(), carry);
                else
                {
                    digits.insert(digits.begin(), carry);
                }
            }
        }

        return digits;
    }
};

int main()
{
    Solution Sol;
    vector<int> digits = {9, 9, 9, 9};
    vector<int> result = Sol.plusOne(digits);
    // Test case
    for(int nums : result)
    {
        cout << nums;
    }

    return 0;
}