#include <bits/stdc++.h>
using namespace std;

class NQueens
{
    int n;
    vector<vector<string>> solutions;
    vector<string> board;
    bool isSafe(int row, int col)
    {
        for (int i = 0; i < row; i++)
            if (board[i][col] == 'Q')
                return false;
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 'Q')
                return false;
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
            if (board[i][j] == 'Q')
                return false;
        return true;
    }

    void solve(int row)
    {
        if (row == n)
        {
            solutions.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++)
        {
            if (isSafe(row, col))
            {
                board[row][col] = 'Q';
                solve(row + 1);
                board[row][col] = '.';
            }
        }
    }

public:
    NQueens(int size) : n(size)
    {
        board = vector<string>(n, string(n, '.'));
    }

    vector<vector<string>> solveNQueens()
    {
        solve(0);
        return solutions;
    }
};

int main()
{
    int n;
    cin >> n;
    NQueens nq(n);
    vector<vector<string>> ans = nq.solveNQueens();
    cout << ans.size() << "\n";
    for (auto &solution : ans)
    {
        for (auto &row : solution)
        {
            cout << row << "\n";
        }
        cout << "\n";
    }
    return 0;
}
