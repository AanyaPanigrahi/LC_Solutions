class Solution {
public:
    int minsum(vector<vector<int>>& grid, int r, int c, vector<vector<int>> &dp) {
        if(r==grid.size() || c==grid[0].size()) return 1000000000;
        if (r == grid.size() - 1 && c == grid[0].size() - 1) return grid[r][c];
        if (dp[r][c] != -1) return dp[r][c];
        int right = grid[r][c] + minsum(grid, r, c+1, dp);
        int down = grid[r][c] + minsum(grid, r+1, c, dp);
        return dp[r][c]=min(right, down);  
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return minsum(grid,0,0,dp);
    }
};