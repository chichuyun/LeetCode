class Solution {
public:
    int minimumOperations(string leaves) {
        int len = leaves.size();
        vector<int> sum(len+1, 0);

        for(int i=0; i<len; ++i) {
            sum[i+1] += sum[i] + (leaves[i]=='r');
        }
        
        for(int i=1; i<len; ++i) {
            sum[i] = i - 2*sum[i];
        }

        // [0, i) + [i, j) + [j, len)
        // 0 < i < j < n
        // i => [1, len-2]
        // j => [2, len-1]
        int count = INT_MAX;
        int minCount = sum[1];
        for(int j=2; j<len; ++j) {
            minCount = min(minCount, sum[j-1]);
            count = min(count, minCount-sum[j]);
        }

        return count + len - sum[len];
    }
};