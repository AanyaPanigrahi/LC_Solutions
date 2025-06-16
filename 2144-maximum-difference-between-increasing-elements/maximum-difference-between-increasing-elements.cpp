class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int res = -1;
        int n = nums.size();

        if (n < 2)
            return -1;

        int pt1 = 0;
        int pt2 = 1;

        while (pt2 < n) {
            if (nums[pt1] > nums[pt2]) {
                pt1 = pt2;
                pt2++;
            } else {
                res = max(res, nums[pt2] - nums[pt1]);
                pt2++;
            }
        }
        return res == 0 ? -1 : res;
    }
};
