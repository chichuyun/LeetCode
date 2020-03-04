class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int k, n=num_people, next;
        vector<int> nums(num_people,0);
        k = int((sqrt(1.0+8.0*float(candies))-1.0)/(2.0*n));

        nums[0] = ((k*n+2-n)*k)/2;
        for(int i=1;i<n;++i) nums[i] = nums[i-1] + k;
        candies -= ((1+k*n)*k*n/2);
        
        next = k*n + 1;
        for(int i=0;i<n;++i) {
            if(next<candies) {
                nums[i] += next;
                candies -= next;
            } else {
                nums[i] += candies;
                return nums;
            }
            ++next;
        }
        return nums;
    }
};