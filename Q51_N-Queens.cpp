#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> result; // 儲存所有可能的解
        vector<string> board(n, string(n, '.')); // 初始化棋盤，每個位置為 '.' *注意 不可用 "."
        vector<int> cols(n, 0), diag1(2 * n - 1, 0), diag2(2 * n - 1, 0); 
        // cols 追蹤哪些列已被佔用
        // diag1 追蹤左上到右下對角線（row - col 相同）
        // diag2 追蹤右上到左下對角線（row + col 相同）
        
        backtrack(0, n, board, result, cols, diag1, diag2);
        return result;
    }

private:
    void backtrack(int row, int n, vector<string>& board, vector<vector<string>>& result, vector<int>& cols, vector<int>& diag1, vector<int>& diag2)
    {
        if (row == n)
        { // 如果已成功放置 n 個皇后
            result.push_back(board); // 將當前棋盤加入解答
            return;
        }

        for (int col = 0; col < n; col++)
        { 
            if (cols[col] || diag1[row - col + n - 1] || diag2[row + col])
            {
                continue; // 如果當前列或對角線被佔用，跳過
            } 

            // 放置皇后
            board[row][col] = 'Q';
            cols[col] = diag1[row - col + n - 1] = diag2[row + col] = 1;

            // 遞迴處理下一列
            backtrack(row + 1, n, board, result, cols, diag1, diag2);

            // 回溯：移除皇后，嘗試下一個位置
            board[row][col] = '.';
            cols[col] = diag1[row - col + n - 1] = diag2[row + col] = 0;
        }
    }
};

int main()
{
    Solution Sol;
    int n = 8; // n-queens 
    vector<vector<string>> result = Sol.solveNQueens(n);

    for (const auto& board : result)
    {
        for (const auto& row : board)
        {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}