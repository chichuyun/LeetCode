class Solution {
private:
    vector<vector<string>> strs;
    vector<int> rows, lefts, rights;

    void backtrace(vector<string>& nums, int& n, int j) {
        if(j==n) {
            strs.push_back(nums);
            return;
        }
        for(int i=0;i<n;++i) {
            int k1=i+j, k2=i-j+n-1;
            if(rows[i]==0 && lefts[k1]==0 && rights[k2]==0) {
                rows[i] = 1;
                lefts[k1] = 1;
                rights[k2] = 1;
                nums[j][i] = 'Q';
                backtrace(nums, n, j+1);
                rows[i] = 0;
                lefts[k1] = 0;
                rights[k2] = 0;
                nums[j][i] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        if(n < 1) return strs;
        vector<string> nums;
        nums.resize(n);
        rows.resize(n);
        lefts.resize(2*n-1);
        rights.resize(2*n-1);

        string str(n,'.');
        for(int i=0;i<n;++i) nums[i] = str;
        backtrace(nums, n, 0);
        return strs;
    }
};