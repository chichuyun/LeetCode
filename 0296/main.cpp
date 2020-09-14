class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int rows = grid.size();
        int cols = grid[0].size();

        vector<int> row_indexs;
        for(int i=0; i<rows; ++i) {
            for(int j=0; j<cols; ++j) {
                if(grid[i][j] == 1) {
                    row_indexs.push_back(i);
                }
            }
        }
        
        vector<int> col_indexs;
        for(int j=0; j<cols; ++j) {
            for(int i=0; i<rows; ++i) {
                if(grid[i][j] == 1) {
                    col_indexs.push_back(j);
                }
            }
        }

        int l = 0, r = row_indexs.size()-1;
        int count = 0;
        while(l < r) {
            count += row_indexs[r] - row_indexs[l];
            count += col_indexs[r] - col_indexs[l];
            --r; ++l;
        }

        return count;
    }
};