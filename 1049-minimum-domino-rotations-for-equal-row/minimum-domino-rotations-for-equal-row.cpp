class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int ans = n + 1;

        for (int i = 1; i <= 6; i++) {
            int top_cnt = 0, bottom_cnt = 0, top_swap = 0, bottom_swap = 0;

            for (int j = 0; j < n; j++) {
               if (tops[j] == i)
                    top_cnt++;
                else if (bottoms[j] == i) {
                    top_cnt++;
                    top_swap++;
                }
                if (bottoms[j] == i)
                    bottom_cnt++;
                else if (tops[j] == i) {
                    bottom_cnt++;
                    bottom_swap++;
                }

                if (top_cnt == n)
                    ans = min(ans, top_swap);
                if (bottom_cnt == n)
                    ans = min(ans, bottom_swap);
            }
        }

        return (ans == n + 1) ? -1 : ans;
    }
};
