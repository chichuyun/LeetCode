class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> nums(num+1,0);
        int count=1, pre=1, base=1, con=1, half=0;
        for(int i=1;i<=num;++i) {
            if(count>half) con = 1;
            nums[i] = nums[i-pre] + con;
            --count;
            if(count==0) {
                half = base;
                base << 1;
                pre = base;
                count = base;
                con = 0;
            }
        }
        return nums;
/*
        vector<int> nums(num+1, 0);
        for(int i=1; i<=num; i++){
            nums[i] = nums[i&(i-1)]+1;
        }
        return dp;
*/
    }
};