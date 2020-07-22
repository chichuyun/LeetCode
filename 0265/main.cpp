class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if(costs.empty() || costs[0].empty()) return 0;
        if(costs.size() == 1 && costs[0].size() == 1) return costs[0][0];

        int cors = costs[0].size();
        vector<int> dp(cors, 0), dp2(cors, 0);
        int k, min_v, count;

        for(int i=1; i<=costs.size(); ++i) {
            for(int j=0; j<cors; ++j) dp2[j] = dp[j];
            min_v = INT_MAX;
            count = 0;
            for(int j=0; j<cors; ++j) if(min_v > dp2[j]) min_v = dp2[j];
            for(int j=0; j<cors; ++j) if(min_v == dp2[j]) {++count; k = j;}

            for(int j=0; j<cors; ++j) {
                if(count > 1 || j != k) {
                    dp[j] = min_v + costs[i-1][j];
                } else {
                    int min_v2 = INT_MAX;
                    for(int j=0; j<cors; ++j) if(min_v2 > dp2[j] && min_v != dp2[j]) min_v2 = dp2[j];
                    dp[k] = min_v2 + costs[i-1][k];
                }
            }
        }

        min_v = INT_MAX;
        for(int j=0; j<cors; ++j) if(min_v > dp[j]) min_v = dp[j];

        return min_v;
    }
};