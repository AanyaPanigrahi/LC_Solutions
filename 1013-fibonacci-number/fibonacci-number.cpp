class Solution {
public:
    int fibo(int n, vector<int> &dp){
        if(n==0 || n==1) return n; //base case
        if(dp[n]!=-1) return dp[n];
        return dp[n]=fibo(n-1,dp)+fibo(n-2,dp);
    }

    int fib(int n) {
        //naive
        // if(n==0 || n==1) return n;
        // return fib(n-1)+fib(n-2);
        vector<int> dp(n+1,-1);
        return fibo(n, dp);
    }
};