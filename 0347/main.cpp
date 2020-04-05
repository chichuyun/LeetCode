struct low{
    bool operator()(pair<int,int> p, pair<int,int> q) const {
        return p.first < q.first;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> maps;
        priority_queue<pair<int,int>, vector<pair<int,int>>, low> ques;
        for(int n : nums) ++maps[n];
        for(auto p : maps) ques.emplace(p.second,p.first);
        vector<int> res;
        for(int i=0;i<k;++i) {
            res.push_back(ques.top().second);
            ques.pop();
        }
        return res;
    }
};