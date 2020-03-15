class Solution {
private:
    vector<int> nums;
    int helper(string s, int i) {
        if(i<=s.size()-1 && s[i]=='0') {
            return 0;
        } else if(i>=s.size()-1) {
            return 1;
        }
        
        if(nums[i]!=0) {
            return nums[i];
        }
        int count = helper(s, i+1);
        if(stoi(s.substr(i,2))<27) count += helper(s, i+2);
        
        nums[i] = count;
        return count;
    }
public:
    int numDecodings(string s) {
        nums.resize(s.size());
        return helper(s, 0);
    }
};