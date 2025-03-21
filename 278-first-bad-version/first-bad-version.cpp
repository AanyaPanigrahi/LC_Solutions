// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l=1;
        int h=n;
        int ans=-1;
        if(n==0 || n==1){
            return n;
        }
        while(l<=h){
            int mid=l+(h-l)/2;
            bool flag=isBadVersion(mid);
            if(flag==true){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};