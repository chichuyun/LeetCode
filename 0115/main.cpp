class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<long>> nums(s.size()+1,vector<long>(t.size()+1,0));
        for(int i=0;i<=s.size();++i) nums[i][t.size()] = 1;
        for(int i=s.size()-1;i>=0;--i) {
            for(int j=t.size()-1;j>=0;--j) {
                if(s[i]==t[j]) {
                    nums[i][j] += nums[i+1][j+1] + nums[i+1][j];
                } else {
                    nums[i][j] += nums[i+1][j];
                }
            }
        }
        return nums[0][0];
    }
};