class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> front;
        int count=0, num0=0, num1=0, temp;
        int l, r, t, b;
        for(int i=0;i<grid.size();++i) {
            for(int j=0;j<grid[0].size();++j) {
                if(grid[i][j]!=0) ++num0;
                if(grid[i][j]==2) ++num1;
            }
        }
        if(num0==num1) return 0;
        do {
            temp = num1;
            front = grid;
            for(int i=0;i<grid.size();++i) {
                for(int j=0;j<grid[0].size();++j) {
                    if(front[i][j]==1) {
                        l = 0;
                        r = grid.size()-1;
                        t = 0;
                        b = grid[0].size()-1;
                        if(i - 1 > l) l = i - 1;
                        if(i + 1 < r) r = i + 1;
                        if(j - 1 > t) t = j - 1;
                        if(j + 1 < b) b = j + 1;
                        if(front[i][t]==2 || front[l][j]==2 || 
                           front[i][b]==2 || front[r][j]==2) grid[i][j] = 2;
                        if(grid[i][j]==2) {
                            num1++;
                        }
                    }
                }
            }
            ++count;
        } while(temp!=num1);
        if(num0==num1) {
            return count-1;
        } else {
            return -1;
        }
    }
};