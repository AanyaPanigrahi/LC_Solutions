class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        int cur = 0, ans = n + 1;
        vector<int> bitcount(32, 0);

        while (i <= j && j < n) {
            cur |= nums[j];
            for (int bit = 0; bit < 32; bit++) {
                if (nums[j] & (1 << bit)) {
                    bitcount[31 - bit]++;
                }
            }
            while (i <= j && cur >= k) {
                ans = min(ans, j - i + 1);

                for (int bit = 0; bit < 32; bit++) {
                    if (nums[i] & (1 << bit)) {
                        bitcount[31 - bit]--;
                    }
                }

                i++;

                int temp = 0;
                for (int bit = 31; bit>= 0; bit--) {
                    if (bitcount[bit]) {
                        temp += pow(2, 31 - bit);
                    }
                }
                cur = temp;
            }
            j++;
        }
        if (ans == n + 1)
            return -1;
        return ans;
    }
};