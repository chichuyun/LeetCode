class Solution {
private:
    unordered_map<int,int> nums;
    int dp(vector<int>& coins, int amount) {
        if(amount<0) return -1;   // this way does not work
        if(amount==0) return 0;   // at least have one
        if(nums.find(amount)!=nums.end()) return nums[amount];
        
        int minCount=INT_MAX;
        for(int coin : coins) {
            int num = dp(coins,amount-coin);
            if(num>=0) minCount = min(minCount, num);
        }
        nums[amount] = minCount==INT_MAX ? -1 : minCount+1;
        return nums[amount];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        return dp(coins, amount);
    }
};