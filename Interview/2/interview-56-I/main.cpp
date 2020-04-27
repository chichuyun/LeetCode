class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        vector<int> res(2,0);
        int num = 0;
        for(int& n : nums) num ^= n;
        int mask = 1;
        while((num&mask)==0) mask <<= 1;
        for(int& n : nums) {
            if(n&mask) {
                res[0] ^= n;
            } else {
                res[1] ^= n;
            }
        }
        return res;
    }
};