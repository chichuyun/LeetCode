class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        for(int& n : A) {
            n %= K;
            if(n < 0) n += K;
        }
        vector<int> nums(K);
        nums[0] = 1;
        int count = 0, num = 0;
        for(int& n : A) {
            num += n;
            if(num >= K) num -= K;
            count += nums[num];
            ++nums[num];
        }
        return count;
    }
};