class Solution {
private:
    unordered_map<int,int> nums={{1,1},{2,2}};
public:
    int numWays(int n) {
        if(n==0) {
            return 1;
        } else if(n==1) {
            return 1;
        } else if(n==2) {
            return 2;
        }

        if(nums[n]!=0) return nums[n];
        int num = numWays(n-2) + numWays(n-1);
        nums[n]= num%1000000007;
        return nums[n];
    }
};