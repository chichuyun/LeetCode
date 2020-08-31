class Solution {
private:
    bool check(int countOne, vector<vector<int>>& grid) {
        queue<pair<int,int>> nodes;
        int rows = grid.size(), cols = grid[0].size();
        bool flag = false;
        for(int i=0; i<rows; ++i) {
            for(int j=0; j<cols; ++j) {
                if(grid[i][j]==1) {
                    grid[i][j] = 2;
                    nodes.emplace(i, j);
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        int countTwo = 0;
        while(!nodes.empty()) {
            pair<int, int> node = nodes.front();
            int n = nodes.size();
            int x = node.first, y = node.second;
            nodes.pop();
            ++countTwo;
            while(n--) {
                if(x > 0      && grid[x-1][y]==1) {nodes.emplace(x-1, y); grid[x-1][y] = 2;}
                if(x < rows-1 && grid[x+1][y]==1) {nodes.emplace(x+1, y); grid[x+1][y] = 2;}
                if(y > 0      && grid[x][y-1]==1) {nodes.emplace(x, y-1); grid[x][y-1] = 2;}
                if(y < cols-1 && grid[x][y+1]==1) {nodes.emplace(x, y+1); grid[x][y+1] = 2;}
            }
        }
        for(int i=0; i<rows; ++i) {
            for(int j=0; j<cols; ++j) {
                if(grid[i][j]==2) grid[i][j] = 1;
            }
        }
        return countTwo != countOne;
    }
public:
    int minDays(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int countOne = 0;
        int rows = grid.size(), cols = grid[0].size();
        
        for(int i=0; i<rows; ++i) {
            for(int j=0; j<cols; ++j) {
                if(grid[i][j]==1) {
                    ++countOne;
                }
            }
        }
        
        if(countOne <= 1) return countOne;
        if(check(countOne, grid)) return 0;
        
        for(int i=0; i<rows; ++i) {
            for(int j=0; j<cols; ++j) {
                if(grid[i][j]==1) {
                    grid[i][j] = 0;
                    if(check(countOne-1, grid)) return 1;
                    grid[i][j] = 1;
                }
            }
        }

        return 2;
    }
};