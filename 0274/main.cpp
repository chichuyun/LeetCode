class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        vector<int> nums(len+1,0);
        for(int n : citations) {
            if(n>len) {
                ++nums[len];
            } else {
                ++nums[n];
            }
        }
        int count = 0;
        for(int i=len;i>=0;--i) {
            count += nums[i];
            if(count >= i) return i;
        }
        return 0;
    }
};