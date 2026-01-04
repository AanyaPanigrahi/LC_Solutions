class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for (int x : nums) {
            int val = checkOne(x);
            if (val != -1) sum += val;
        }
        return sum;
    }

    int checkOne(int n) {
        int e = round(cbrt(n));
        if ((long long)e * e * e == n && isPrime(e)) {
            return 1 + e + e*e + e*e*e; }

        for (int i=2; i*i<=n; i++) {
            if (n%i==0) {
                int a=i, b=n/i;
                if (a!=b && isPrime(a) && isPrime(b)) {
                    return 1+a+b+n; }

                return -1;
            }
        }
        return -1;
    }

    bool isPrime(int s) {
        if (s<2) return false;
        for (int i=2; i*i<=s; i++) {
            if (s%i==0) return false;
        }
        
        return true;
    }
};