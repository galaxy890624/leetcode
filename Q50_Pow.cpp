#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        return pow(x, n);
    }
};

int main()
{
    Solution Sol;
    double x = 0.5;
    int n = -2;
    // Test case
    double result = Sol.myPow(x, n);

    cout << result << endl;

    return 0;
}