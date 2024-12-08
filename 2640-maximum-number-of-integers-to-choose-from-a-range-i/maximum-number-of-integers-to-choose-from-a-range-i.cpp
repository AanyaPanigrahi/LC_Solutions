class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        bitset<10001> xNot = 0;
        for (int x : banned)
            xNot[x] = 1;
        int sum = 0, count = 0;
        for (int x = 1; x <= n && sum <= maxSum; x++) {
            if (!xNot[x]) {
                sum += x;
                count++;
            }
        }
        return (sum <= maxSum) ? count : count- 1;
    }
};