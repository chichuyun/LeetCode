class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int len = croakOfFrogs.size();
        if(len%5) return -1;
        int count = 0;
        vector<int> ans(5,0);
        unordered_map<char,int> nums = {{'c',0},{'r',1},{'o',2},{'a',3},{'k',4}};
        for(char s : croakOfFrogs) {
            int n = nums[s];
            ++ans[n];
            if(n!=0 && ans[n]>ans[n-1]) return -1;
            count = max(count, ans[0]-ans[4]);
        }
        return count;
    }
};