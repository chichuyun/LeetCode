class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if(intervals.empty() || intervals[0].empty()) return 0;
        
        
        int count = 0, res = 0;
        vector<pair<int,int>> nums;
        for(auto& p : intervals) {
            nums.emplace_back(p[0], 1);
            nums.emplace_back(p[1], -1);
        }
        sort(nums.begin(), nums.end());

        for(auto& t : nums) {
            count += t.second;
            res = max(res, count);
        }

        return res;
    }
};