class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        const int n=nums.size();
        if (nums[0]==nums[1]){
            return nums[0];
        }
        if (nums[2]==nums[0] || nums[2]==nums[1]){
            return nums[2];
        }
        int cndidate, count=0;
        for(int i=3; i<n; i++){
            const int s=nums[i];
            if (count==0){
                cndidate=s;
            }
            count+=2*(s==cndidate)-1;
            if (count>=2){
                return s;
            }
        }
        return cndidate;
    }
};