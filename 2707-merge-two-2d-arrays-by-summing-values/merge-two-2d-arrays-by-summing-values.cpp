class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1,
                                    vector<vector<int>>& nums2) {
        map<int, int> h;
        for (auto& num : nums1) {
            h[num[0]] += num[1];
        }
        for (auto& num : nums2) {
            h[num[0]] += num[1];
        }
        vector<vector<int>> nums;
        for (auto& [k, v] : h) {
            nums.push_back({k, v});
        }
        return nums;
    }
};