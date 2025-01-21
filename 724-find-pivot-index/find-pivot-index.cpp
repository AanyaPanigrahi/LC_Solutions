class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> prefixsum(nums.size());
        vector<int> suffixsum(nums.size());

        prefixsum[0] = 0;
        for (int i = 1; i < nums.size(); i++) {
            prefixsum[i] = prefixsum[i - 1] + nums[i - 1];
        }

        suffixsum[nums.size() - 1] = 0;
        for (int i = nums.size()-2; i >=0; i--) {
            suffixsum[i] = suffixsum[i + 1] + nums[i + 1];
        }

        for(int i=0; i<nums.size();i++){
            if(prefixsum[i]==suffixsum[i]){
                return i;
            }
        }
        return -1;
    }

}
;