class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.empty()) return 0;
        int len = nums.size();
        vector<int> dp(nums.size(),0);
        int end = min(nums[0],len-1);
        for(int i=1;i<=end;++i) dp[i] = 1;
        for(int i=1;i<len;++i) {
            end = min(nums[i]+i,len-1);
            for(int j=nums[i-1]+i-1;j<=end;++j) {
                if(dp[j]==0) {
                    dp[j] = dp[i] + 1;
                } else {
                    dp[j] = min(dp[j], dp[i]+1);
                }
            }
        }
        return dp[len-1];
/*
    int ans = 0;
    int end = 0;
    int maxPos = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
        maxPos = max(nums[i] + i, maxPos);
        if (i == end) {
            end = maxPos;
            ans++;
        }
    }
    return ans;
*/
    }
};