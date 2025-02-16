#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int MinPrice = INT_MAX; // 追蹤目前的最小價格
        int MaxProfit = 0;      // 追蹤最大的利潤

        for (int price : prices)
        {
            if (price < MinPrice)
            {
                MinPrice = price; // 更新最小價格
            }
            else if (price - MinPrice > MaxProfit)
            {
                MaxProfit = price - MinPrice; // 更新最大利潤
            }
        }
        return MaxProfit;
    }
};

int main()
{
    Solution Sol;
    // Test case
    // 1 <= prices.size() <= 10^5
    // 0 <= prices[index] <= 10^4
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int MaxProfit = Sol.maxProfit(prices);

    for(int element : prices)
    {
        cout << element << " ";
    }
    cout << endl;
    cout << MaxProfit << endl;

    return 0;
}