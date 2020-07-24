class Solution {
private:
    vector<char> mems;
    unordered_map<char, int> maps;
    vector<string> nums;

    void helper(int k, vector<string> cens) {
        int count = 0;
        char r;
        for(auto& p : mems) {
            if(count == 0) {
                r = p;
                count = 1;
            } else {
                if(r == p) {
                    continue;
                } else {
                    r = p;
                }
            }
            if(maps[p] < 1) continue;
            maps[p]--;
            string side = string(1, p);
            if(k==mems.size()-1) {
                for(auto& c : cens) nums.push_back(side+c+side);
            } else {
                vector<string> strs;
                for(auto& c : cens) strs.push_back(side+c+side);
                helper(k+1, strs);
            }
            maps[p]++;
        }
    }

public:
    vector<string> generatePalindromes(string s) {
        if(s.size()<2) return vector<string>(1,s);

        unordered_map<char, int> strs;
        
        for(auto& str : s) strs[str]++;
        
        int count = 0;
        char cen=' ';  // even
        for(auto& p : strs) {
            if(p.second%2==1) {
                ++count;
                cen = p.first;  // odd
            }
        }

        if(s.size()%2==1 && count!=1) return {};  // odd
        if(s.size()%2==0 && count!=0) return {};  // even
        
        if(cen!=' ' and strs[cen]==1) strs.erase(cen);  // only one element;

        for(auto& p : strs) {
            for(int i=0; i<p.second/2; ++i) mems.push_back(p.first);
        }
        for(auto& p : mems) maps[p]++;

        if(cen == ' ') {
            helper(0, vector<string>(1,""));  // even
        } else {
            helper(0, vector<string>(1,string(1,cen))); // odd
        }
        
        return nums;
    }
};