class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rows=board.size(), cols=board[0].size();
        for(int i=0;i<rows;++i) {
            for(int j=0;j<cols;++j) {
                int count=0;
                if(i-1>=0) {
                    if(board[i-1][j]>0) ++count;
                    if(j-1>=0 && board[i-1][j-1]>0) ++count;
                    if(j+1<cols && board[i-1][j+1]>0) ++count;
                }
                if(i+1<rows) {
                    if(board[i+1][j]>0) ++count;
                    if(j-1>=0 && board[i+1][j-1]>0) ++count;
                    if(j+1<cols && board[i+1][j+1]>0) ++count;
                }
                if(j-1>=0 && board[i][j-1]>0) ++count;
                if(j+1<cols && board[i][j+1]>0) ++count;

                if((count<2 || count>3) && board[i][j]==1) {  // 1 => 0
                    board[i][j] = 2;
                }
                if(count==3 && board[i][j]==0) {  // 0 => 1
                    board[i][j] = -1;
                }
            }
        }
        for(int i=0;i<rows;++i) {
            for(int j=0;j<cols;++j) {
                if(board[i][j]==2) {
                    board[i][j] = 0;
                } else if(board[i][j]==-1) {
                    board[i][j] = 1;
                }
            }
        }
    }
};