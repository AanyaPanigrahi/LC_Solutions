class Solution {
public:

    void Combinations(int ind, int target, vector <int> & arr,
    vector <vector<int>> & res, vector <int> & abc) {
        if (target == 0) {
        res.push_back(abc);
        return;
        }
        for (int i = ind; i < arr.size(); i++) {
            if (i > ind && arr[i] == arr[i - 1]) continue;
            if (arr[i] > target) break;
            abc.push_back(arr[i]);
            Combinations(i + 1, target - arr[i], arr, res, abc);
            abc.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector <vector<int>> res;
        vector <int> abc;
        Combinations(0, target, candidates, res, abc);
        return res;
    }
};