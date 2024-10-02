class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& a) {
        vector<int> arr_copy = a;
        sort(arr_copy.begin(), arr_copy.end());

        int rank = 1;
        unordered_map<int, int> um;
        for (int i = 0; i < arr_copy.size(); i++) {
            if (um.find(arr_copy[i]) == um.end()) {
                um[arr_copy[i]] = rank;
                rank++;
            }
        }

        vector<int> ans(a.size());
        for (int i = 0; i < a.size(); i++) {
            ans[i] = um[a[i]];
        }

        return ans;
    }
};