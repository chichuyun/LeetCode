class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.empty()) return nums1;
        unordered_map<int,int> finds;
        for(int i=0;i<nums1.size();++i) finds[nums1[i]] = i;
        vector<int> nums(nums1.size(), -1);
        stack<int> nexts; // monotonous increasing stack
        for(int i=0;i<nums2.size();++i) {
            while(!nexts.empty() && nexts.top()<nums2[i]) {
                int num = nexts.top();
                if(finds.count(num)) nums[finds[num]] = nums2[i];
                nexts.pop();
            }
            nexts.push(nums2[i]);
        }
        return nums;
    }
};