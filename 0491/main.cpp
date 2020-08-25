class Solution {
private:
    struct _func {
        bool operator()(vector<int>& p, vector<int>& q) {
            return p.back() > q.back();
        }    
    };
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        if(nums.size() < 2) return {};
        vector<vector<int>> res0, res;
        
        priority_queue<vector<int>, vector<vector<int>>, _func> que1, que2;
        for(int i=0; i<nums.size(); ++i) {
            while(!que1.empty()) {
                vector<int> num = que1.top();
                que2.push(num);
                if(num.back() <= nums[i]) {
                    num.push_back(nums[i]);
                    que2.push(num);
                }
                que1.pop();
            }
            swap(que1, que2);
            que1.push({nums[i]});
        }
        
        while(!que1.empty()) {
            vector<int> num = que1.top();
            if(num.size() > 1) res0.push_back(num);
            que1.pop();
        }

        sort(res0.begin(), res0.end());
        for(int i=0; i<res0.size(); ++i) {
            if(res.empty() || res0[i] != res0[i-1]) res.push_back(res0[i]);
        }

        return res;
    }
};