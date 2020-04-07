struct great {
    bool operator()(const pair<int,string>& p, const pair<int,string>& q) const {
        if(p.first != q.first) {
            return p.first > q.first;
        } else {
            return p.second < q.second;
        }
        return false;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> nums;
        for(string w : words) ++nums[w];
        priority_queue<pair<int,string>, vector<pair<int,string>>, great> ques;
        for(auto num : nums) {
            ques.emplace(num.second, num.first);
            if(ques.size()>k) ques.pop();
        }
        vector<string> res(k);
        for(int i=0;i<k;++i) {
            res[i] = ques.top().second;
            ques.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};