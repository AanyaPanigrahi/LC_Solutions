class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int size = nums.size();
        int maxOR = 0, maxORCnt = 0;
        int totalSS = (1 << size) - 1;
        for (int ssMask = 1; ssMask <= totalSS; ssMask++) {
            int currOR = 0;
            for (int indx = 0; indx < size; indx++) {
                if ((1 << indx) & ssMask) {
                    currOR |= nums[indx];
                }
            }
            if (currOR == maxOR) {
                maxORCnt++;
            } else if (currOR > maxOR) {
                maxOR = currOR;
                maxORCnt = 1;
            }
        }
        return maxORCnt;
    }
};