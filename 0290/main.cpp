class Solution {
public:
    bool wordPattern(string pattern, string str) {
        if(pattern.empty() || str.empty()) return false;
        unordered_map<char,string> table;
        unordered_set<string> strs;
        string temp;
        int count=0;

        str.push_back(' ');
        int i=0, j;
        for(char c : pattern) {
            j = i;
            while(str[i]!=' ') ++i;
            temp = str.substr(j,i-j);
            if(table.find(c)==table.end()) {
                if(strs.find(temp)==strs.end()) {
                    table[c] = temp;
                    strs.insert(temp);
                } else {
                    return false;
                }
            } else if(table[c]!=temp) {
                return false;
            }
            ++i;
            ++count;
            if(i>=str.size()) break;
        }
        if(count!=pattern.size()) return false;
        for(;i<str.size();++i) {
            if(str[i]!=' ') return false;
        }
        return true;
    }
};