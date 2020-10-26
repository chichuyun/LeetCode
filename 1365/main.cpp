class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> counts(101);
        vector<int> res;
        for(int& n : nums) counts[n]++;
        for(int i=1; i<=100; ++i) {
            counts[i] += counts[i-1];
        }

        for(int& n : nums) {
            if(n == 0) {
                res.push_back(0);
            } else {
                res.push_back(counts[n-1]);
            }
        }

        return res;
    }
};