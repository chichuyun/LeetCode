typedef pair<long,int> pairs;
struct pair_fun {
    bool operator()(pairs& p1, pairs& p2) {
        return p1.first > p2.first;
    }
};

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> indexs(primes.size(),0);
        vector<long> dp(n,0);
        dp[0] = 1;
        for(int i=1;i<n;++i) {
            priority_queue<pairs, vector<pairs>, pair_fun> nums;
            for(int j=0;j<primes.size();++j) {
                nums.emplace(dp[indexs[j]]*primes[j],j);
            }
            dp[i] = nums.top().first;
            pairs num = nums.top();
            while(!nums.empty() && nums.top().first==num.first) {
                ++indexs[nums.top().second];
                nums.pop();
            }
        }
        return dp[n-1];
    }
};