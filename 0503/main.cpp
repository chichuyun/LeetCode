class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len,-1);
        stack<int> indexs;
        for(int i=0;i<2*len;++i) {
            int j = i%len;
            while(!indexs.empty() && nums[indexs.top()] < nums[j]) {
                int k = indexs.top();
                indexs.pop();
                res[k] = nums[j];
            }
            if(i < len) indexs.push(i);
        }
        return res;
    }
};