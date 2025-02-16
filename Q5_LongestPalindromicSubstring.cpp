#include <iostream>
#include <cstdlib>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.length() == 0)
        {
            return ""; // 如果字符串為空，直接返回空串。
        }
        string Longest = ""; // 保存最長回文子串。

        // 遍歷所有可能的滑動窗口
        for (int LeftPtrIndex = 0; LeftPtrIndex < s.length(); LeftPtrIndex++)
        {
            for (int RightPtrIndex = LeftPtrIndex; RightPtrIndex < s.length(); RightPtrIndex++)
            {
                // 檢查當前窗口是否是回文
                if (isPalindrome(s, LeftPtrIndex, RightPtrIndex))
                {
                    int SlidingWindowLength = RightPtrIndex - LeftPtrIndex + 1; // 窗口長度
                    // 如果比之前的最長回文子串更長，更新答案
                    if (SlidingWindowLength > Longest.length())
                    {
                        Longest = s.substr(LeftPtrIndex, SlidingWindowLength);
                    }
                }
            }
        }

        return Longest; // 返回最長回文子串。
    }

private:
    // 判斷 s[left:right] 是否是回文子串
    bool isPalindrome(const string& s, int LeftPtrIndex, int RightPtrIndex)
    {
        while (LeftPtrIndex < RightPtrIndex)
        {
            if (s[LeftPtrIndex] != s[RightPtrIndex])
            {
                return false; // 如果兩端字符不同，則不是回文。
            }
            LeftPtrIndex++;
            RightPtrIndex--;
        }
        return true; // 如果完成比較，則是回文。
    }
};

int main()
{
    Solution Sol;
    // Test case
    // 1 <= s.length() <= 1000
    // s consist of only digits and English letters.
    string s = "babad";
    string result = Sol.longestPalindrome(s);

    cout << "s = " << s << endl;
    cout << "result = " << result << endl;

    return 0;
}