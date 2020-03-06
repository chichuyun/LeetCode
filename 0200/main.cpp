class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0) return 0;
        int cols=grid.size(), rows=grid[0].size();
        int i, j, l, r, t, b, count=0;
        queue<pair<int,int>> indexs;
        pair<int,int> nums;
        
        for(int px=0;px<cols;++px) {
            for(int py=0;py<rows;++py) {
                if(grid[px][py]!='1') continue;
                
                grid[px][py] = '2';
                indexs.push(make_pair(px,py));
                while(!indexs.empty()) {
                    nums = indexs.front();
                    indexs.pop();
                    i = nums.first;
                    j = nums.second;
                    l = i - 1;
                    r = i + 1;
                    t = j - 1;
                    b = j + 1;
                    if(l >= 0) {
                        if(grid[l][j]=='1') {
                            grid[l][j]='2';
                            indexs.push(make_pair(l,j));
                        }
                    }
                    if(r < cols) {
                        if(grid[r][j]=='1') {
                            grid[r][j]='2';
                            indexs.push(make_pair(r,j));
                        }
                    }
                    if(t >= 0) {
                        if(grid[i][t]=='1') {
                            grid[i][t]='2';
                            indexs.push(make_pair(i,t));
                        }
                    }
                    if(b < rows) {
                        if(grid[i][b]=='1') {
                            grid[i][b]='2';
                            indexs.push(make_pair(i,b));
                        }
                    }
                }
                ++count;
            }
        }
        return count;
    }
};