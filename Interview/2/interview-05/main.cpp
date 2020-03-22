class Solution {
public:
    string replaceSpace(string s) {
        ostringstream res;
        for(char ss : s) {
            if(ss==' ') {
                res<<"%20";
            } else {
                res<<ss;
            }
        }
        return res.str();
    }
};