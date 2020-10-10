class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int len = nums.size();
        vector<int> counts(len+1, 0);
        for(int& n : nums) {
            counts[n]++;
        }
        vector<int> res;
        for(int i=1; i<=len; ++i) {
            if(counts[i]>1) res.push_back(i);
        }
        for(int i=1; i<=len; ++i) {
            if(counts[i]==0) res.push_back(i);
        }
        return res;
    }
};