#include<unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        vector<int> res(2);
        for(int i=0;i<nums.size();++i) {
            if(map.find(target - nums[i])!=map.end()) {
                res[0] = map[target - nums[i]];
                res[1] = i;
            } else {
                map[nums[i]] = i;
            }
        }
        return res;
    }
};