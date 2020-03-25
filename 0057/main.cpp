class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> nums;
        if(intervals.empty() || intervals[0].empty()) {
            nums.push_back(newInterval);
            return nums;
        }
        
        vector<int> intv(newInterval);
        int i=0, flag=0;
        int left=newInterval[0], right=newInterval[1];
        while(i < intervals.size()) {
            if(left > intervals[i][1] || flag==2) {
                nums.push_back(intervals[i++]);
            } else if(flag==0) {
                if(left >= intervals[i][0]) {
                    intv[0] = intervals[i][0];
                }
                flag = 1;
            } else if(flag==1) {
                if(right > intervals[i][1]) {
                    ++i;
                } else {
                    if(right >= intervals[i][0]) {
                        intv[1] = intervals[i][1];
                        ++i;
                    }
                    nums.push_back(intv);
                    flag = 2;
                }
            }
        }
        if(right > intervals[i-1][1]) nums.push_back(intv);
        return nums;
    }
};