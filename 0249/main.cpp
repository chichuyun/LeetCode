class Solution {
private:
    string makeFirst(string& str) {
        int num = str[0] - 'a';
        string res = str;
        for(int i=0; i<str.size(); ++i) {
            if(str[i]-num >= 'a') {
                res[i] = str[i] - num;
            } else {
                res[i] = str[i] - num + 26;
            }
        }
        return res;
    }
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> maps;
        vector<string> first_eles(strings.size());
        for(int i=0; i<strings.size(); ++i) {
            first_eles[i] = makeFirst(strings[i]);
        }
        
        for(int i=0; i<strings.size(); ++i) {
            maps[first_eles[i]].push_back(strings[i]);
        }

        vector<vector<string>> strs;
        for(auto& p : maps) {
            strs.push_back(p.second);
        }

        return strs;
    }
};