class Solution {
public:
    int minCapability(vector<int>& a, int k) {
        vector<int> b = a;
        sort(b.begin(), b.end());
        int l = b[0], r = b.back(), mid, ans = r;

        while (l <= r) {
            mid = l + (r - l) / 2;
            int x = robbingHouses(a, mid, k);
            if (x >= k) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

public:
    int robbingHouses(vector<int>& a, int val, int k) {
        int count = 0;
        for (int i = 0; i < a.size();) {
            if (a[i] <= val) {
                count++;
                i += 2;
            } else {
                i++;
            }
        }
        return count;
    }
};