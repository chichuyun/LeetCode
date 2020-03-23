class Solution {
private:
    vector<vector<int>> cols, rows;
    vector<vector<vector<int>>> nums;
    vector<int> str={0,1,2,3,4,5,6,7,8};

    bool backtrace(vector<vector<char>>& board, int n) {
        for(int c=n;c<81;++c) {
            int i = c/9, j = c%9;
            if(board[i][j]=='.') {
                for(int k : str) {
                    if(cols[i][k]!=1 && rows[j][k]!=1 && nums[i/3][j/3][k]!=1) {
                        cols[i][k] = 1;
                        rows[j][k] = 1;
                        nums[i/3][j/3][k] = 1;
                        board[i][j] = char(k) + '1';
                        if(backtrace(board, c+1)) return true;
                        cols[i][k] = 0;
                        rows[j][k] = 0;
                        nums[i/3][j/3][k] = 0;
                    }
                }
                board[i][j] = '.';
                return false;
            }
        }
        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        nums.resize(3); cols.resize(9); rows.resize(9);
        for(int i=0;i<9;++i) {
            cols[i].resize(9);
            rows[i].resize(9);
        }
        for(int i=0;i<3;++i) {
            nums[i].resize(3);
            for(int j=0;j<3;++j) {
                nums[i][j].resize(9);
            }
        }
        for(int i=0;i<9;++i) {
            for(int j=0;j<9;++j) {
                if(board[i][j]!='.') {
                    int k = board[i][j] - '1';
                    cols[i][k] = 1;
                    rows[j][k] = 1;
                    nums[i/3][j/3][k] = 1;
                }
            }
        }
        backtrace(board, 0);
    }
};