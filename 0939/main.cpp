class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        if(points.size()<4) return 0;

        map<int,set<int>> nums;
        vector<int> rows;
        int minArea=INT_MAX;
        for(auto &p : points) nums[p[0]].insert(p[1]);
        for(auto &ps : nums) rows.push_back(ps.first);
        for(int i=0;i<rows.size();++i) {
            if(nums[rows[i]].size()<2) continue;
            for(int j=i+1;j<rows.size();++j) {
                if(nums[rows[j]].size()<2) continue;
                for(auto x : nums[rows[i]]) {
                    for(auto y : nums[rows[j]]) {
                        if(x!=y && nums[rows[i]].count(y) && nums[rows[j]].count(x)) {
                            minArea = min(minArea,(rows[j]-rows[i])*abs(x-y));
                        }
                    }
                }
            }
        }
        return minArea == INT_MAX ? 0 : minArea;
    }
};