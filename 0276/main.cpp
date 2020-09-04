class Solution {
public:
    int numWays(int n, int k) {
        if(k==0 || n==0) return 0;
        int a1 = k;
        int a2 = k*k;
        int an;

        if(n==1) {
            an = a1;
        } else if(n==2) {
            an = a2;
        } else {
            n -= 2;
            while(n--) {
                an = (k-1)*(a1 + a2);
                a1 = a2;
                a2 = an;
            }
        }
        return an;
    }
};