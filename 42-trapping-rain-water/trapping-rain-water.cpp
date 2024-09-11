class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int lm[n],rm[n];
        lm[0]=height[0];
        rm[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            lm[i]=max(height[i],lm[i-1]);
        }
        for(int j=n-2;j>=0;j--){
            rm[j]=max(height[j],rm[j+1]);
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=min(rm[i],lm[i])-height[i];
        }
        return sum;
    }
};