class Solution {
public:
    int minChanges(string s) {
        int n = s.length();
        int ans = 0;

        int i = 0, j = 1;

        while (j < n) {

            if (s[i] != s[j])
                ans += 1;

            i += 2;
            j += 2;
        }
        return ans;
    }
};