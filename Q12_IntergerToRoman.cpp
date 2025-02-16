#include <iostream>
#include <cstdlib>

using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        // Use a vector of pairs to map values to their Roman numerals in descending order
        vector<pair<int, string>> values = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"},
            {1, "I"}
        };

        string result = "";

        // Iterate through the values, subtracting and building the Roman numeral string
        for (const auto& [value, roman] : values)
        {
            while (num >= value)
            {
                num -= value;
                result += roman;
            }
        }

        return result;
    }
};

int main()
{
    Solution Sol;
    // Test case
    int num = 3493; // 1 <= num <= 3999
    string intToRoman = Sol.intToRoman(num);
    cout << "num = " << num << endl;
    cout << "result = " << intToRoman << endl;

    return 0;
}