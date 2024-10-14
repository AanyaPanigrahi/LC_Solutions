class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long> maxHeap;
        for (int num : nums) {
            maxHeap.push(num);
        }

        long long score = 0;
    
    for (int i = 0; i < k; ++i) {
        long long maxVal = maxHeap.top();
        maxHeap.pop();

        score += maxVal;

        maxHeap.push((maxVal + 2) /  3); 
    }

    return score;

}
}
;