class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int flag=0, count=0, jj;
        for(int i=0;i<8;++i) {
            for(int j=0;j<8;++j) {
                if(board[i][j]=='R') {
                    for(int x=i+1;x<8;++x) {
                        if(board[x][j]!='.') {
                            if(board[x][j]=='p') ++count;
                            break;
                        }
                    }
                    for(int x=i-1;x>=0;--x) {
                        if(board[x][j]!='.') {
                            if(board[x][j]=='p') ++count;
                            break;
                        }
                    }
                    flag = 1;
                    jj = j;
                    break;
                }
            }
            if(flag) {
                for(int y=jj+1;y<8;++y) {
                    if(board[i][y]!='.') {
                        if(board[i][y]=='p') ++count;
                        break;
                    }
                }
                for(int y=jj-1;y>=0;--y) {
                    if(board[i][y]!='.') {
                        if(board[i][y]=='p') ++count;
                        break;
                    }
                }
                break;
            }
        }
        return count;
    }
};