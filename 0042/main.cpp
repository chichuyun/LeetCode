class Solution {
public:
    int trap(vector<int>& height) {
        stack<pair<int,int>> nums;
        int count=0, pre=0;
        for(int i=0;i<height.size();++i) {
            int h = height[i];
            if(!nums.empty() && h>=nums.top().first) {
                pre = nums.top().first;
                nums.pop();
                while(!nums.empty() && nums.top().first<=h) {
                    count += (nums.top().first - pre)*(i-1-nums.top().second);
                    pre = nums.top().first;
                    nums.pop();
                }
                if(!nums.empty()) {
                    count += (h - pre)*(i-1-nums.top().second);
                }
                nums.emplace(h,i);
            } else {
                nums.emplace(h,i);
            }
        }
        return count;
    }
};

/*
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left(height);
        vector<int> right(height);
        for(int i=1;i<height.size();++i) {
            left[i] = max(left[i],left[i-1]);
        }
        for(int i=height.size()-2;i>=0;--i) {
            right[i] = max(right[i],right[i+1]);
        }
        int count=0;
        for(int i=0;i<height.size();++i) {
            count += min(left[i],right[i]) - height[i];
        }

        return count;
    }
};
*/