class Solution {
public:
    long long coloredCells(int n) {
        vector<long long> ans(n+1);
        ans[1]=1;
        for(int m=2;m<=n;m++){
            ans[m]=ans[m-1]+4*m-4;
        }
        return ans[n];
    }
};