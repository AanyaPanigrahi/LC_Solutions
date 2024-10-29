class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> dp(row, vector<int>(col, 1));

        for (int j = col - 2; j >= 0; j--) {
            for (int i = 0; i < row; i++) {
                int val = grid[i][j];

                int max_move = val < grid[i][j + 1] ? dp[i][j + 1] : 0;

                if (i < row - 1) {
                    max_move =
                        max(max_move,
                            val < grid[i + 1][j + 1] ? dp[i + 1][j + 1] : 0);
                }

                if (i > 0) {
                    max_move =
                        max(max_move,
                            val < grid[i - 1][j + 1] ? dp[i - 1][j + 1] : 0);
                }


                dp[i][j] = 1 + max_move;
            }
        }

        int ans = 0;
        for (int i = 0; i < row; i++) {
            ans = max(ans, dp[i][0]);
        }

        return ans - 1;
    }
};