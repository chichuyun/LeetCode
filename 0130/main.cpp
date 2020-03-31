class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty()) return;
        queue<pair<int,int>> nums;
        int rows=board.size(), cols=board[0].size();
        for(int i=0;i<rows;++i) if(board[i][0]=='O') nums.emplace(i,0);
        for(int j=0;j<cols;++j) if(board[0][j]=='O') nums.emplace(0,j);
        for(int i=0;i<rows;++i) if(board[i][cols-1]=='O') nums.emplace(i,cols-1);
        for(int j=0;j<cols;++j) if(board[rows-1][j]=='O') nums.emplace(rows-1,j);
        int count;
        while(!nums.empty()) {
            count = nums.size();
            while(count--) {
                pair<int,int> p = nums.front();
                int i = p.first, j = p.second;
                board[i][j] = 'Y';
                if(i-1>=0   && board[i-1][j]=='O') nums.emplace(i-1,j);
                if(i+1<rows && board[i+1][j]=='O') nums.emplace(i+1,j);
                if(j-1>=0   && board[i][j-1]=='O') nums.emplace(i,j-1);
                if(j+1<cols && board[i][j+1]=='O') nums.emplace(i,j+1);
                nums.pop();
            }
        }
        for(int i=0;i<rows;++i) {
            for(int j=0;j<cols;++j) {
                if(board[i][j]=='O') {
                    board[i][j] = 'X';
                } else if(board[i][j]=='Y') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};