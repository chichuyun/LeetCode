class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int res=0, rows=matrix.size(), cols=matrix[0].size();
        vector<vector<int>> dp(rows+1,vector<int>(cols+1,0));
        int num = 0;
        for(int i=1;i<=rows;++i) {
            for(int j=1;j<=cols;++j) {
                if(matrix[i-1][j-1]=='1') {
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                    num = max(dp[i][j], num);
                }
            }
        }
        return num*num;
    }
};