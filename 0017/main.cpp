class Solution {
private:
    unordered_map<char, string> nums = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                                        {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                                        {'8', "tuv"}, {'9', "wxyz"}};
    void backtrace(vector<string>& res, string& digits, int n, string str) {
        if(n==digits.size()) {
            res.push_back(str);
            return;
        }
        for(char s : nums[digits[n]]) {
            backtrace(res, digits, n+1, str+s);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty()) return res;
        backtrace(res, digits, 0, "");
        return res;
    }
};