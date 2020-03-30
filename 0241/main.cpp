struct pair_hash {
    size_t operator()(pair<int,int> p) const {
        return hash<int>()(p.first) ^ hash<int>()(p.second);
    }
};

class Solution {
private:
    vector<int> nums;
    vector<char> opers;
    unordered_map<pair<int,int>, vector<int>, pair_hash> hists;
    unordered_map<char,function<int(int,int)>> opmap = {
        {'+', plus<int>()}, {'-', minus<int>()}, {'*', multiplies<int>()}
    };

    vector<int> helper(int m, int n) {
        if(m==n) return {nums[n]};
        pair<int,int> p = make_pair(m,n);
        if(hists.count(p)) return hists[p];
        vector<int> res;

        for(int i=m;i<n;++i) {
            vector<int> left = helper(m,i);
            vector<int> right = helper(i+1,n);
            for(auto l : left) {
                for(auto r : right) {
                    res.push_back(opmap[opers[i]](l,r));
                }
            }
        }
        hists[p] = res;
        return res;
    }

public:
    vector<int> diffWaysToCompute(string input) {
        if(input.empty()) return {};
        ostringstream ss;
        for(auto s : input) {
            if(s=='+' || s=='-' || s=='*') {
                nums.push_back(stoi(ss.str()));
                ss.str("");
                opers.push_back(s);
            } else {
                ss<<s;
            }
        }
        nums.push_back(stoi(ss.str()));
        return helper(0, opers.size());
    }
};