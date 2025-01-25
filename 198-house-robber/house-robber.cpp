class Solution {
public:
    int rob(vector<int>& nums) {
        //two var approach
        int pre2=0;
        int pre1=0;
        for(int i:nums){
            int curr=max(pre2+i,pre1);
            pre2=pre1;
            pre1=curr;
        }
        return pre1;
    }
};