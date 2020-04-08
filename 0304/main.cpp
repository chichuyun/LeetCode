class NumMatrix {
private:
    vector<vector<int>> nums;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return;
        nums.resize(matrix.size()+1,vector<int>(matrix[0].size()+1,0));
        for(int i=0;i<matrix.size();++i) {
            for(int j=0;j<matrix[0].size();++j) {
                nums[i+1][j+1] = matrix[i][j];
            }
        }
        for(int i=1;i<nums.size();++i) {
            for(int j=1;j<nums[0].size();++j) {
                nums[i][j] += nums[i-1][j] + nums[i][j-1] - nums[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return nums[row2+1][col2+1] + nums[row1][col1] -
               nums[row1][col2+1] - nums[row2+1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */