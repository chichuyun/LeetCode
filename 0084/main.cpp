class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(-1);
        stack<int> nums;
        int res = 0, top;
        for(int i=0;i<heights.size();++i) {
            if(nums.empty() || heights[nums.top()] <= heights[i]) {
                nums.push(i);
            } else {
                while(!nums.empty() && heights[nums.top()] > heights[i]) {
                    top = nums.top();
                    res = max((i-top)*heights[top], res);
                    nums.pop();
                }
                nums.push(top);
                heights[top] = heights[i];
            }
        }
        return res;
    }
};