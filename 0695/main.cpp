class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        
        int cols=grid.size(), rows=grid[0].size();
        int x, y, count=0, max=0;
        queue<pair<int,int>> indexs;
        for(int i=0;i<cols;++i) {
            for(int j=0;j<rows;++j) {
                if(grid[i][j]) {
                    grid[i][j] = 0;
                    count = 0;
                    indexs.emplace(i,j);
                    while(!indexs.empty()) {
                        ++count;
                        x = indexs.front().first;
                        y = indexs.front().second;
                        indexs.pop();
                        if(x-1>=0 && grid[x-1][y]) {
                            indexs.emplace(x-1,y);
                            grid[x-1][y] = 0;
                        }
                        if(x+1<cols && grid[x+1][y]) {
                            indexs.emplace(x+1,y);
                            grid[x+1][y] = 0;
                        }
                        if(y-1>=0 && grid[x][y-1]) {
                            indexs.emplace(x,y-1);
                            grid[x][y-1] = 0;
                        }
                        if(y+1<rows && grid[x][y+1]) {
                            indexs.emplace(x,y+1);
                            grid[x][y+1] = 0;
                        }
                    }
                    max = max > count ? max : count;
                }
            }
        }

        return max;
    }
};