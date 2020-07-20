class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(g.empty() || s.empty()) return 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0, j = 0;
        int count = 0;

        while(j < g.size()) {
            while(i < s.size() && s[i] < g[j]) ++i;
            if(i < s.size()) {
                ++j;
                ++i;
                ++count;
            } else {
                break;
            }
        }

        return count;
    }
};