class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(g.empty() || s.empty()) return 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int j = 0;
        int count = 0;

        for(int i=0; i<s.size(); ++i) {
            if(j < g.size() && s[i] < g[j]) continue;
            while(j < g.size()) {
                if(g[j] <= s[i]) {
                    ++count;
                    ++j;
                    break;
                }
                ++j;
            }
        }

        return count;
    }
};