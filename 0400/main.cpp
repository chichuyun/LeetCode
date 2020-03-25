class Solution {
public:
    int findNthDigit(int n) {
        if(n<10) return n;
        int k=n, i=1;
        long base=9;
        while(k > base) {
            k -= base;
            ++i;
            base = 9*i*pow(10,i-1);
        }
        int c = i - k%i;
        if(c==i) c = 0;
        n = pow(10,i-1) + k/i - (k%i==0);
        while(c) {
            n /= 10;
            --c;
        }
        return n%10;
    }
};