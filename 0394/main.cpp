class Solution {
public:
    string decodeString(string s) {
        stack<int> nums;
        stack<string> strs;
        string num, str, temp;

        for(int i=0;i<s.size();++i) {
            char c = s[i];
            if(c>=48 && c<=57) {
                num += c;
            } else if(c=='[') {
                strs.push(str);
                str.clear();
                nums.push(stoi(num));
                num.clear();
            } else if(c==']') {
                temp = str;
                for(int j=0;j<nums.top()-1;++j) {
                    str += temp;
                }
                str = strs.top() + str;
                strs.pop();
                nums.pop();
            } else {
                str += c;
            }
        }
        return str;
    }
};