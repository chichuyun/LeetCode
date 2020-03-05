class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int res=0, max;
        max = (int)(sqrt(2*N+0.25)-0.5);
        for(int i=1;i<=max;++i) {
            if((N-(i-1)*i/2)%i==0) {
                ++res;
            }
        }
        return res;
/*
        int count = 0;
        for(int i = 1;i<=N;i++){
            count+=(N%i==0?1:0);
            N=N-i;
        }
        return count;
*/
    }
};