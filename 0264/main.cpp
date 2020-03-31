class Solution {
public:
    int nthUglyNumber(int n) {
       int p2=0, p3=0, p5=0;
       int num;
       vector<int> dp(n,0);
       dp[0] = 1;
       for(int i=1;i<n;++i) {
           num = min(dp[p2]*2, min(dp[p3]*3, dp[p5]*5));
           dp[i] = num;
           if(num == dp[p2]*2) ++p2;
           if(num == dp[p3]*3) ++p3;
           if(num == dp[p5]*5) ++p5;
       }
       return dp[n-1];
/*
        long top, num;
        unordered_set<long> sets;
        priority_queue<long, vector<long>, greater<long>> nums;
        vector<long> lsts = {2,3,5};
        nums.push(1);
        for(int i=0;i<n;++i) {
            top = nums.top();
            nums.pop();
            for(long n : lsts) {
                num = top*n;
                if(sets.count(num)==0) {
                    sets.insert(num);
                    nums.push(num);
                }
            }
        }
        return top;
*/
    }
};