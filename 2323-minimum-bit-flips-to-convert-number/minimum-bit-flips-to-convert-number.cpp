class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count = 0; 
        int xorans = start ^ goal;
        while(xorans>0){ 
            count += xorans & 1;
            xorans >>=1;
        }
        return count;
    }
};