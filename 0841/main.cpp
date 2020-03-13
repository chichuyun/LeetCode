class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> nums(rooms.size(),0);
        queue<int> nexts;
        
        nexts.push(0);
        while(!nexts.empty()) {
            int next = nexts.front();
            nexts.pop();
            nums[next] = 1;
            for(int n : rooms[next]) {
                if(nums[n]==0) nexts.push(n);
            }
        }
        for(int i=0;i<nums.size();++i) {
            if(nums[i]==0) return false;
        }
        return true;
    }
};