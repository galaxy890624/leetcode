#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s)
    {
        int left = 0;
        int right = s.size() - 1;
        
        // Two-pointer approach to swap elements
        while (left < right)
        {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};

int main()
{
    Solution Sol;
    // Test case
    // 1 <= s.size() <= 10^5
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};  // Use single quotes for chars, don't use double quotes

    cout << "Original string: ";
    for (char element : s)
    {
        cout << element;
    }
    cout << endl;
    
    // Call the reverseString function
    Sol.reverseString(s);
    
    cout << "Reversed string: ";
    for (char element : s)
    {
        cout << element;
    }
    cout << endl;

    return 0;
}