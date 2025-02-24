class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res=nums[0];
        int maxTill=nums[0];
        for(int i=1;i<nums.size();i++){
            maxTill=max(maxTill+nums[i],nums[i]);
            res=max(res,maxTill);
        }
        return res;
    }
};