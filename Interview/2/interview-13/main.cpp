class Solution {
private:
    vector<vector<int>> nums;

    bool helper(int x, int y, int& k) {
        int res=0;
        while(x) { res += x%10; x /= 10; }
        while(y) { res += y%10; y /= 10; }
        return res <= k;
    }
public:
    int movingCount(int m, int n, int k) {
        if(k<0) return 0;
        nums.resize(m);
        for(int i=0;i<m;++i) nums[i].resize(n);
        stack<pair<int,int>> trace;
        pair<int,int> temp;
        int count=0;
        trace.emplace(0,0);
        nums[0][0] = 1;
        while(!trace.empty()) {
            int i = trace.top().first;
            int j = trace.top().second;
            trace.pop();
            ++count;
            if(i-1 >= 0 && nums[i-1][j]==0 && helper(i-1,j,k)) {
                trace.emplace(i-1,j);
                nums[i-1][j] = 1;
            }
            if(i+1 < m && nums[i+1][j]==0 && helper(i+1,j,k)) {
                trace.emplace(i+1,j);
                nums[i+1][j] = 1;
            }
            if(j-1 >= 0 && nums[i][j-1]==0 && helper(i,j-1,k)) {
                trace.emplace(i,j-1);
                nums[i][j-1] = 1;
            }
            if(j+1 < n && nums[i][j+1]==0 && helper(i,j+1,k)) {
                trace.emplace(i,j+1);
                nums[i][j+1] = 1;
            }
        }
        return count;
    }
};