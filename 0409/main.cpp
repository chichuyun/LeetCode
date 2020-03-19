class Solution {
public:
    int longestPalindrome(string s) {
        cout<<s.size()<<endl;
        unordered_map<char,int> nums;
        for(char str : s) {
            ++nums[str];
        }
        int odd=0, res=0;
        for(auto str : nums) {
            int num = str.second;
            if(num%2) {
                odd = 1;
                res += num-1;
            } else {
                res += num;
            }
        }
        return res+odd;
    }
};