class Solution {
public:
    int minSteps(int n) {
        vector<int> nums(n+1,0);
        for(int i=2;i<=n;++i) {
            for(int j=1;j<i;++j) {
                if(i%j==0) {
                    if(nums[i]==0) {
                        nums[i] = i/j + nums[j];
                    } else {
                        nums[i] = min(nums[i], i/j+nums[j]);
                    }
                }
            }
        }
        return nums[n];
/* Greedy Algorithm
        if(n == 1) return 0;
        for(int i = n / 2; i > 1; i--) {
            if(n % i == 0) {
                return minSteps(i) + n / i;
            }
        }
        return n;
*/
    }
};