class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int maxDay = days.back();
        int minDay = days.front();
        vector<int> dp(maxDay + 1, 0);
        unordered_set<int> travelDays(days.begin(), days.end());

        for (int i = minDay; i <= maxDay; i++) {
            if (travelDays.find(i) == travelDays.end()) {
                dp[i] = dp[i - 1];
            } else {
                dp[i] = dp[i - 1] + costs[0]; // 1-day pass
                dp[i] = min(dp[i], (i - 7 >= 0 ? dp[i - 7] : 0) +
                                       costs[1]); // 7-day pass
                dp[i] = min(dp[i], (i - 30 >= 0 ? dp[i - 30] : 0) +
                                       costs[2]); // 30-day pass
            }
        }

        return dp[maxDay];
    }
};
