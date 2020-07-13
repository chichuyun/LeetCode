class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> maxs;
        unordered_set<int> sets;
        for(int& n : nums) {
            if(maxs.size() < 3 && sets.count(n)==0) {
                maxs.push(n);
                sets.insert(n);
            } else {
                if(n > maxs.top() && sets.count(n)==0) {
                    sets.erase(maxs.top());
                    sets.insert(n);
                    maxs.pop();
                    maxs.push(n);
                }
            }
        }
        if(sets.size()==1) return nums[0];
        if(sets.size()==2) {
            maxs.pop();
            return maxs.top();
        }
        return maxs.top();
    }
};