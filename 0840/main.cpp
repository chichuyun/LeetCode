class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if(grid.size()<3 || grid[0].size()<3) return 0;
        int rows = grid.size(), cols = grid[0].size();
        for(int i=0;i<rows;++i) {
            for(int j=0;j<cols;++j) {
                if(grid[i][j]>9 || grid[i][j]==0) grid[i][j] = 100;
            }
        }
        vector<vector<int>> rs(rows,vector<int>(cols-2));
        vector<vector<int>> cs(rows-2,vector<int>(cols));
        for(int i=0;i<rows;++i) {
            for(int j=0;j<cols-2;++j) {
                rs[i][j] = grid[i][j] + grid[i][j+1] + grid[i][j+2];
            }
        }
        for(int i=0;i<rows-2;++i) {
            for(int j=0;j<cols;++j) {
                cs[i][j] = grid[i][j] + grid[i+1][j] + grid[i+2][j];
            }
        }
        int l1, l2, count=0;
        for(int i=0;i<rows-2;++i) {
            for(int j=0;j<cols-2;++j) {
                unordered_set<int> nums;
                nums.insert(grid[i][j]);  nums.insert(grid[i][j+1]);  nums.insert(grid[i][j+2]);
                nums.insert(grid[i+1][j]);nums.insert(grid[i+1][j+1]);nums.insert(grid[i+1][j+2]);
                nums.insert(grid[i+2][j]);nums.insert(grid[i+2][j+1]);nums.insert(grid[i+2][j+2]);
                l1 = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];
                l2 = grid[i+2][j] + grid[i+1][j+1] + grid[i][j+2];
                if(nums.size()==9 && l1<100 && l1==l2 &&
                   l1==rs[i][j] && l1==rs[i+1][j] && l1==rs[i+2][j] &&
                   l1==cs[i][j] && l1==cs[i][j+1] && l1==cs[i][j+2]) {
                    ++count;
                }
            }
        }
        return count;
    }
};