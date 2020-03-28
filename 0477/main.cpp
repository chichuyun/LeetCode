class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
//        ios::sync_with_stdio(false);cin.tie(0);
        vector<int> bytes(32,0);
        unsigned int n, m;
        for(auto num : nums) {
            n = ~num;
            for(int i=0;i<32;++i) {
                bytes[i] += n&1;
                n >>= 1;
            }
        }
        
        int count = 0;
        for(auto num : nums) {
            n = ~num;
            m = num;
            for(int i=0;i<32;++i) {
                count += (bytes[i] - (n&1))*(m&1);
                n >>= 1;
                m >>= 1;
            }
        }
        return count;
    }
};