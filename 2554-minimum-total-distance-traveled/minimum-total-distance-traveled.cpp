class Solution {
public:
    long long solve(vector<int>& rb, vector<vector<int>>& fc, int i, int j,
                    vector<vector<vector<long long>>>& dp) {
        if (i >= rb.size())
            return 0;

        if (j >= fc.size())
            return LONG_MAX;

        if (dp[i][j][fc[j][1]] != -1)
            return dp[i][j][fc[j][1]];

        long long notTake = solve(rb, fc, i, j + 1, dp);

        long long take = 1e15;

        if (fc[j][1] > 0) {
            int distance = abs(rb[i] - fc[j][0]);
            fc[j][1]--;
            take = distance + solve(rb, fc, i + 1, j, dp);
            fc[j][1]++;
        }

        return dp[i][j][fc[j][1]] = min(take, notTake);
    }

    long long minimumTotalDistance(vector<int>& robot,
                                 vector<vector<int>>& factory) {
    sort(robot.begin(), robot.end());
    sort(factory.begin(), factory.end());

    vector<vector<vector<long long>>> dp(
        robot.size(),
        vector<vector<long long>>(factory.size(), vector<long long>(101, -1)));
    return solve(robot, factory, 0, 0, dp);
}
}
;