class Solution {
private:
    unordered_map<int,int> nums;
    int helper(int n) {
        if(nums.count(n)) return nums[n];
        int count=0;
        for(int i=0;i<n;++i) {
            count += helper(i)*helper(n-i-1);
        }
        nums[n] = count;
        return count;
    }
public:
    int numTrees(int n) {
        nums[0] = 1;
        nums[1] = 1;

        return helper(n);
    }
};