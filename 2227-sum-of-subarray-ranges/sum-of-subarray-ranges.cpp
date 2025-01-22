class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        stack<int> st;

        // max elements
        vector<long long> left_max(n), right_max(n);

        // prev smaller element
        st = stack<int>();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            left_max[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // next smaller element
        st = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            right_max[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // min elements
        vector<long long> left_min(n), right_min(n);

        // prev greater element
        st = stack<int>();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            left_min[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // next greater element
        st = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            right_min[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // sum
        for (int i = 0; i < n; i++) {
            long long max_contribution =
                nums[i] * 1LL * (i - left_max[i]) * (right_max[i] - i);
            long long min_contribution =
                nums[i] * 1LL * (i - left_min[i]) * (right_min[i] - i);
            sum += (max_contribution - min_contribution);
        }

        return sum;
    }
};