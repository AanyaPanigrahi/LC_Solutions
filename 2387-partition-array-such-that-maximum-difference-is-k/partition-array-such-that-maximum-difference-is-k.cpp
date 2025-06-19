class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int p1 = 0, p2 = 0;
        int count = 1;
        while (p2 < nums.size()) {
            if (nums[p2] - nums[p1] > k) {
                count++;
                p1 = p2;
            }
            p2++;
        }
        return count;
    }
};
