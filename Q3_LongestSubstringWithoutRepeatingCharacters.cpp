#include <iostream>
#include <cstdlib>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> CharSet; // To store unique characters in the window
        int Left = 0;               // Left pointer of the sliding window
        int MaxLength = 0;          // Maximum length of substring
    
        for (int Right = 0; Right < s.length(); ++Right)
        {
            // If character is already in the set, shrink the window
            while (CharSet.find(s[Right]) != CharSet.end())
            {
                CharSet.erase(s[Left]);
                ++Left;
            }
            // Add the current character to the set
            CharSet.insert(s[Right]);
            // Update the maximum length
            MaxLength = max(MaxLength, Right - Left + 1);
        }
    
        return MaxLength;
    }
};

int main()
{
    Solution Sol;
    // Test case

    // 0 <= s.length() <= 5 * 10^4
    // s consists of English letters, digits, symbols and spaces.
    string s = "pwwkew";
    int result = Sol.lengthOfLongestSubstring(s);

    cout << "input = " << s << endl;
    cout << s.length() << endl;
    cout << "lengthOfLongestSubstring = " << result << endl;

    return 0;
}