class Solution {
public:
    string reformat(string s) {
        ostringstream nums, strs;
        for(char& str : s) {
            if(str>='0' && str<='9') {
                nums<<str;
            } else {
                strs<<str;
            }
        }
        string num = nums.str();
        string str = strs.str();
        if(abs((int)num.size()-(int)str.size())>1) return "";
        ostringstream ss;
        if(num.size()>str.size()) swap(num,str);
        for(int i=0;i<num.size();++i) {
            ss<<str[i]<<num[i];
        }
        if(num.size()!=str.size()) {
            ss<<str[str.size()-1];
        }
        return ss.str();
    }
};