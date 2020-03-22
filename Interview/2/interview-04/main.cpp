class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        int rows=matrix.size(), cols=matrix[0].size();
        int i=0, j=cols-1;
        
        while(i>=0 && i<rows && j>=0 && j<cols) {
            if(matrix[i][j]==target) {
                return true;
            } else if(matrix[i][j]>target) {
                --j;
            } else {
                ++i;
            }
        }
        return false;
    }
};