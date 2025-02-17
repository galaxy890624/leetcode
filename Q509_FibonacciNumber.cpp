#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution
{
public:
    int fib(int n) {
        vector<int> Ans(n + 1); // From 0 to 30 has 31 elements
        // Boundary condition
        if( n == 0 )
        {
            return 0;
        }
        if( n == 1 )
        {
            return 1;
        }
        // Other condition
        // Without Ans[0], Ans[1] below, can't use Ans[Index] = Ans[Index - 1] + Ans[Index - 2];
        Ans[0] = 0;
        Ans[1] = 1;
        for(int Index = 2; Index <= n; Index++)
        {
            Ans[Index] = Ans[Index - 1] + Ans[Index - 2];
        }
        return Ans[n];
    }
};

int main()
{
    Solution Sol;
    // Test case
    // 0 <= n <= 30
    for(int n = 0; n <= 30; n++)
    {
        cout << "n = " << n << ", " << "fib" << "(" << n << ")" << " = " << Sol.fib(n) << endl; 
    }
}