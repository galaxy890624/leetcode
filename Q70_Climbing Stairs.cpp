#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> dp(n + 1); // 如果 n = 45，我們需要 46 個元素來正確存取 dp[45]
        // Boundary condition
        if(n == 1)
        {
        	return 1;
		}
		if(n == 2)
		{
			return 2;
		}
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

int main()
{
    Solution Sol;
    int n = 45;
    int result = Sol.climbStairs(n);
    cout << result << endl;
    for(int i = 0; i <= n; i++)
    {
        cout << "dp" << "[" << i << "]" << "=" << Sol.climbStairs(i) << endl;
    }
    return 0;
}
