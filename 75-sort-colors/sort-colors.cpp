class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                swap(nums[i],nums[l]);
                l++;
            }
        }
        for(int j=l;j<nums.size();j++){
            if(nums[j]==1){
                swap(nums[j],nums[l]);
                l++;
            }

        }
    }
};