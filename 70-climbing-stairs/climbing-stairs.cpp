class Solution {
public:

    //memoization
    int count(vector<int>& dp,int n){
        if(n==0 || n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=count(dp,n-1)+count(dp,n-2);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        if(n<0) return -1;
        return count(dp,n);
    }
};