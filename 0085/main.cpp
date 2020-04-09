class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int res=0, rows=matrix.size(), cols=matrix[0].size();
        vector<vector<int>> col(rows+1,vector<int>(cols+1,0));
        int num;
        for(int i=1;i<=rows;++i) {
            for(int j=1;j<=cols;++j) {
                if(matrix[i-1][j-1]=='1') {
                    col[i][j] = col[i][j-1] + 1;
                    num = col[i][j];
                    for(int k=i;k>0;--k) {
                        num = min(num, col[k][j]);
                        res = max(res, num*(i-k+1));
                    }
                }
            }
        }
        return res;
    }
};