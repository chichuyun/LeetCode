class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2) return false;
        stack<char> strs;
        
        for(char& str : s) {
            if(str=='(' || str=='[' || str=='{') {
                strs.push(str);
            } else {
                if(strs.empty()) return false;
                if(str==')') {
                    if(strs.top()!='(') return false;
                    strs.pop();
                } else if(str==']') {
                    if(strs.top()!='[') return false;
                    strs.pop();
                } else {
                    if(strs.top()!='{') return false;
                    strs.pop();
                }
            }
        }

        return strs.empty();
    }
};