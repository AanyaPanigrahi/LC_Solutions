class Solution {
public:
    int minCost(vector<int>& cost, int idx, vector<int>& dp) {
        if(idx>=cost.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int onestep = cost[idx] + minCost(cost, idx+1, dp);
        int twostep = cost[idx] + minCost(cost, idx+2, dp);
        return dp[idx]=min(onestep,twostep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1,-1);
        return min(minCost(cost,0,dp),minCost(cost,1,dp));
    }
};