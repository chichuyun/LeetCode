class Solution {
private:
    unordered_map<long,int> nums;
    long helper(long n) {
        if(n==1) return 0;
        if(nums[n]!=0) return nums[n];
        if(!(n&1)) return helper(n>>1)+1;
        long res = min(helper(n-1), helper(n+1))+1;
        nums[n] = res;
        return res;
    }
public:
    int integerReplacement(int n) {
        return helper(n);
    }
};