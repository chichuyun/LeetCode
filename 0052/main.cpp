class Solution {
    vector<int> rows, lefts, rights;

    void backtrace(int& count, int& n, int j) {
        if(j==n) {
            ++count;
            return;
        }
        for(int i=0;i<n;++i) {
            int k1=i+j, k2=i-j+n-1;
            if(rows[i]==0 && lefts[k1]==0 && rights[k2]==0) {
                rows[i] = 1;
                lefts[k1] = 1;
                rights[k2] = 1;
                backtrace(count, n, j+1);
                rows[i] = 0;
                lefts[k1] = 0;
                rights[k2] = 0;
            }
        }
    }
public:
    int totalNQueens(int n) {
        if(n < 1) return 0;
        int count=0;
        rows.resize(n);
        lefts.resize(2*n-1);
        rights.resize(2*n-1);

        backtrace(count, n, 0);
        return count;
    }
};