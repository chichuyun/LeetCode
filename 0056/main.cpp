class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> nums;
        if(intervals.empty() || intervals[0].empty()) return nums;
        sort(intervals.begin(),intervals.end());
        vector<int> num(intervals[0]);
        for(int i=1;i<intervals.size();++i) {
            if(num[1]>=intervals[i][0]) {
                num[1] = max(intervals[i][1], num[1]);
            } else {
                nums.push_back(num);
                num = intervals[i];
            }
        }
        nums.push_back(num);
        return nums;
    }
};