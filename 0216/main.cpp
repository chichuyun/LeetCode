class Solution {
private:
    vector<vector<int>> nums;
    void helper(int& k, int& n, vector<int> num, int m, int start) {
        if(num.size()>k || m>n) return;
        if(num.size()==k) {
            if(m==n) nums.push_back(num);
            return;
        }
        for(int i=start;i<10;++i) {
            num.push_back(i);
            helper(k, n, num, m+i, i+1);
            num.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if(k>9 || n>45 || k<1 || n<1) return {};

        vector<int> num;
        helper(k, n, num, 0, 1);
        return nums;
    }
};