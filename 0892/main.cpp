class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;

        int len=grid.size(), count=0;
        for(int i=0; i<len; ++i) {
            for(int j=0; j<len; ++j) {
                int temp = grid[i][j];
                if(temp) count += temp*4 + 2;
                if(i+1<len) count -= 2*min(temp, grid[i+1][j]);
                if(j+1<len) count -= 2*min(temp, grid[i][j+1]);
            }
        }
        return count;
    }
};