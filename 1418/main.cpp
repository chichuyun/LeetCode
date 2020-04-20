class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        unordered_map<string, unordered_map<string,int>> strs;
        unordered_set<string> ves;
        unordered_set<int> sts;  // tables
        for(auto str : orders) {
            ++strs[str[2]][str[1]];
            sts.insert(stoi(str[1]));
            ves.insert(str[2]);
        }
        vector<vector<string>> nums(sts.size()+1,vector<string>(strs.size()+1,"0"));
        unordered_map<string,int> vegs, tabs;
        vector<string> vs;
        vector<int> ss;
        for(auto s : sts) ss.push_back(s);
        for(auto s : ves) vs.push_back(s);
        sort(vs.begin(), vs.end());
        sort(ss.begin(), ss.end());
        for(int i=0;i<ss.size();++i) {
            tabs[to_string(ss[i])] = i + 1;
        }
        for(int i=0;i<vs.size();++i) {
            vegs[vs[i]] = i + 1;
        }
        int i = 1;
        nums[0][0] = "Table";
        for(auto &p : tabs) {
            nums[p.second][0] = p.first;
        }
        for(auto &p : strs) {
            int num = vegs[p.first];
            nums[0][num] = p.first;
            for(auto &q : p.second) {
                nums[tabs[q.first]][num] = to_string(q.second);
            }
            ++i;
        }
        return nums;
    }
};