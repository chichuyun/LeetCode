class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> nums;
        if(n<1) return nums;

        nums.resize(pow(10,n)-1);
        for(int i=0;i<pow(10,n)-1;++i) {
            nums[i] = i + 1;
        }
        return nums;
    }
};