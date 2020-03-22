class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> nums;
        
        int j=0;
        for(int n : pushed) {
            nums.push(n);
            while(!nums.empty() && nums.top()==popped[j]) {
                nums.pop();
                ++j;
            }
        }
        return nums.empty();
    }
};