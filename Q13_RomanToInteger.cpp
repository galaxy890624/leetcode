#include <iostream>
#include <cstdlib>

using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        // Map of Roman numerals to their values
        unordered_map<char, int> hash = {
            {'I', 1}, {'V', 5}, {'X', 10}, 
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };
    
        // Replace special cases with simpler forms
        size_t pos = 0;
        while ((pos = s.find("IV")) != string::npos)
        {
            s.replace(pos, 2, "IIII");
        }
        while ((pos = s.find("IX")) != string::npos)
        {
            s.replace(pos, 2, "VIIII");
        }
        while ((pos = s.find("XL")) != string::npos)
        {
            s.replace(pos, 2, "XXXX");
        }
        while ((pos = s.find("XC")) != string::npos)
        {
            s.replace(pos, 2, "LXXXX");
        }
        while ((pos = s.find("CD")) != string::npos)
        {
            s.replace(pos, 2, "CCCC");
        }
        while ((pos = s.find("CM")) != string::npos)
        {
            s.replace(pos, 2, "DCCCC");
        }

        // Calculate the integer value
        int num = 0;
        for (char c : s)
        {
            num += hash[c];
        }

        return num;
    }
};

int main()
{
    Solution Sol;
    // Test case
    string s = "MCMXCIV"; // Input a roman number s which contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M') and it is guaranteed that s is a valid roman numeral in the range [1, 3999]
    int romanToInt = Sol.romanToInt(s);

    cout << "s = " << s << endl;
    cout << "romanToInt = " << romanToInt << endl;

    return 0;
}