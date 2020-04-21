class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty()) return "";
        vector<int> counts(128), strs(128);
        for(char ss : t) ++counts[ss];
        int len = t.size(), count = len, res = INT_MAX, l = 0;
        while(l < len && counts[s[l]]==0) ++l;
        int loop = l, left = l;
        char str, num;
        for(int r=l;r<s.size();++r) {
            str = s[r];
            if(counts[str]) {
                ++strs[str];
                if(strs[str] <= counts[str]) --count;
                if(count==0) {
                    for(int i=loop;i<=r;++i) {
                        num = s[i];
                        if(counts[num]!=0) {
                            if(strs[num] >= counts[num]) {
                                --strs[num];
                                l = i;
                            }
                            if(strs[num] < counts[num]) break;
                        }
                    }
                    if(res > r-l+1) {  // update
                        res = r - l + 1;
                        left = l;
                    }
                    loop = l + 1;
                    count = 1;
                }
            }
        }
        return res == INT_MAX ? "" : s.substr(left, res);
    }
};