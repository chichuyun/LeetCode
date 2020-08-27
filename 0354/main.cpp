class Solution {
private:
    static bool _func(vector<int>& p, vector<int>& q) {
        if(p[0] != q[0]) return p[0] < q[0];
        return p[1] > q[1];
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.empty() || envelopes[0].empty()) return 0;

        sort(envelopes.begin(), envelopes.end(), _func);
        
        int len = envelopes.size();
        vector<int> nums(len);
        int max_len = 0, count = 0;
        for(int i=0; i<len; ++i) {
            int num = envelopes[i][1];
            int left = 0, right = max_len;
            while(left < right) {
                int mid = left + (right - left)/2;
                if(nums[mid] >= num) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            count = right;
            nums[count++] = num;
            max_len = max(max_len, count);
        }

        return max_len;
    }
};