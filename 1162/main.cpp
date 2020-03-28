class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return -1;

        queue<pair<int,int>> nums;
        int row=grid.size(), col=grid[0].size();
        for(int i=0;i<row;++i) {
            for(int j=0;j<col;++j) {
                if(grid[i][j]==1) {
                    nums.emplace(i,j);
                }
            }
        }
        if(nums.size()==row*col) return -1;

        int count, res=-1;
        while(!nums.empty()) {
            count = nums.size();
            ++res;
            while(count--) {
                auto p = nums.front();
                int i = p.first, j = p.second;
                nums.pop();
                if(i-1>=0  && grid[i-1][j]==0)  {nums.emplace(i-1,j); grid[i-1][j]=1;}
                if(i+1<row && grid[i+1][j]==0)  {nums.emplace(i+1,j); grid[i+1][j]=1;}
                if(j-1>=0  && grid[i][j-1]==0)  {nums.emplace(i,j-1); grid[i][j-1]=1;}
                if(j+1<col && grid[i][j+1]==0)  {nums.emplace(i,j+1); grid[i][j+1]=1;}
            }
        }
        return res;
    }
};