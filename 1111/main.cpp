class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> nums(seq.size(),0);
        int count=0;
        for(int i=0;i<seq.size();++i) {
            if(seq[i]=='(') {
                ++count;
                if(count%2) nums[i] = 1;
            } else {
                if(count%2) nums[i] = 1;
                --count;
            }
        }
        return nums;
    }
};