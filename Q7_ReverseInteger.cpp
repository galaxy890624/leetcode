#include <iostream>
#include <cstdlib>

using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        // Convert the absolute value of x to a string
        string num = to_string(abs(x));
        
        // Initialize pointers for reversing the string
        int ptr1 = 0;
        int ptr2 = num.length() - 1;
        
        // Reverse the string in-place
        while (ptr1 < ptr2)
        {
            swap(num[ptr1], num[ptr2]);
            ptr1++;
            ptr2--;
        }
        
        // Convert the reversed string back to an integer
        int ans;
        try
        {
            ans = stoi(num);
        }
        catch (...)
        {
            // If conversion fails or overflows, return 0
            return 0;
        }
        
        // Restore the sign
        if (x < 0)
        {
            ans = -ans;
        }
        
        // Check if the result is within the 32-bit signed integer range
        if (ans < INT_MIN || ans > INT_MAX)
        {
            return 0;
        }
        
        return ans;
    }
};

int main()
{
    Solution Sol;
    // Test case
    int x = -1987654321;
    int ans = Sol.reverse(x);

    cout << "x = " << x << endl;
    cout << "reverse = " << ans << endl;

    return 0;
}