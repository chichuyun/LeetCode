class Solution {
private:
    unordered_map<int,int> nums={{0,0},{1,1}};
public:
    int fib(int n) {
        if(n==0) {
            return 0;
        } else if(n==1) {
            return 1;
        } else if(nums[n]!=0) {
            return nums[n];
        }
        
        int f = fib(n-1) + fib(n-2);
        nums[n] = f%1000000007;
        return nums[n];
    }
};