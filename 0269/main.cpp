class Solution {
public:
    string alienOrder(vector<string>& words) {
        if(words.empty()) return "";
        if(words.size()==1) return words[0];

        unordered_map<char, unordered_set<char>> eles;
        unordered_map<char, int> indegrees;

        for(int i=0; i<words.size()-1; ++i) {
            int len = min(words[i].size(), words[i+1].size());
            int j = 0;
            while(j < len && words[i][j]==words[i+1][j]) {
                indegrees[words[i][j]] = 0;
                ++j;
            }
            if(j < len) {
                eles[words[i][j]].insert(words[i+1][j]);
            } else if(words[i].size() > words[i+1].size()) {
                return "";
            }
            for(int k=j; k<words[i].size(); ++k) {
                indegrees[words[i][k]] = 0;
            }
            for(int k=j; k<words[i+1].size(); ++k) {
                indegrees[words[i+1][k]] = 0;
            }
        }
        
        for(auto& p : eles) {
            for(auto& c : p.second) {
                indegrees[c]++;
            }
        }

        queue<char> nodes;
        string res;
        for(auto& c : indegrees) {
            if(c.second==0) nodes.push(c.first);
        }

        while(!nodes.empty()) {
            int n = nodes.size();
            while(n--) {
                char c = nodes.front();
                res.push_back(c);
                nodes.pop();
                for(auto s : eles[c]) {
                    indegrees[s]--;
                    if(indegrees[s]==0) {
                        nodes.push(s);
                    }
                }
            }
        }

        if(res.size()!=indegrees.size()) res = "";

        return res;
    }
};