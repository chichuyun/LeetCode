class Solution {
private:
    vector<string> helper(int n) {
        if(n==1) {
            return {"1", "0", "8"};
        } else if(n==0) {
            return vector<string>(1,"");
        }

        vector<string> strs = helper(n-2);
        vector<string> res;
        for(string& s : strs) {
            res.push_back("0" + s + "0");
            res.push_back("1" + s + "1");
            res.push_back("8" + s + "8");
            res.push_back("6" + s + "9");
            res.push_back("9" + s + "6");
        }
        return res;
    }
public:
    vector<string> findStrobogrammatic(int n) {
        if(n < 1) return {""};
        if(n == 1) return {"1", "0", "8"};

        vector<string> strs = helper(n-2);
        vector<string> res;
        for(string& s : strs) {
            res.push_back("1" + s + "1");
            res.push_back("8" + s + "8");
            res.push_back("6" + s + "9");
            res.push_back("9" + s + "6");
        }

        return res;
    }
};