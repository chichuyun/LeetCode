class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        
        vector<int> nums(n,1);
        int num, i=2;
        for(int i=2;i<n;++i) {
            if(nums[i]!=0) {
                num = i + i;
                while(num < n) {
                    nums[num] = 0;
                    num += i;
                }
            }
        }
        return accumulate(nums.begin(),nums.end(),-2);
    }
};