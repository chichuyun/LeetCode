class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size()<2) return 0;
        int left = 0, right = height.size()-1;
        int count = 0;
        while(left < right) {
            count = max(count, (right-left)*min(height[left],height[right]));
            if(height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }
        return count;
    }
};