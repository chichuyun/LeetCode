class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return;
        int len = matrix.size();
        int rows=len/2, cols;
        if((len&1)==0) {  // even
            cols = rows;
        } else {          // odd
            cols = rows+1;
        }
        for(int i=0;i<rows;++i) {
            for(int j=0;j<cols;++j) {
                int m = i, n = j;
                int num = matrix[m][n];
                for(int k=0;k<3;++k) {
                    matrix[m][n] = matrix[len-1-n][m];
                    int t = m;
                    m = len-1-n;
                    n = t;
                }
                matrix[m][n] = num;
            }
        }
    }
};