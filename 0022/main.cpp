class Solution {
private:
    vector<string> nums;
    
    void helper(int& n, int i, int j, string s) {
        if(i==j && i==n) nums.push_back(s);
        if(i<n) helper(n, i+1, j, s+'(');
        if(j<i) helper(n, i, j+1, s+')');
    }
public:
    vector<string> generateParenthesis(int n) {
        helper(n, 0, 0, "");
        return nums;
    }
};