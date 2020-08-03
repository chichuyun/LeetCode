class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int len = grid.size();
        vector<int> nums(len+1);
        vector<int> lens(len);
        
        for(int i=0; i<len; ++i) {
            int j = len-1, count = 0;
            while(j>=0 && grid[i][j]==0) {++count; --j;}
            nums[count]++;
            lens[i] = count;
        }
        
        int count = nums[len];
        for(int i=len-1; i>=0; --i) {
            count += nums[i];
            if(len-i > count) return -1;
        }
        
        count = 0;
        for(int i=0; i<len; ++i) {
            if(lens[i]>=len-i-1) {
                continue;
            } else {
                int j = i + 1;
                while(j < len && lens[j] < len-i-1) ++j;  // find element fit
                
                int num = lens[i];
                for(int k=j; k>i; --k) {  // insert
                    ++count;
                    lens[k] = lens[k-1];
                }
                lens[i] = lens[j];
            }
        }
        
        return count;
    }
};