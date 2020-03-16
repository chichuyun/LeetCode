class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        if(chars.empty()) return 0;

        unordered_map<char,int> nums;
        int flag, count=0;
        for(char c : chars) {
            ++nums[c];
        }
        for(string str : words) {
            unordered_map<char,int> num(nums);
            flag = 1;
            for(char c : str) {
                if(num[c]!=0) {
                    --num[c];
                } else {
                    flag = 0;
                    break;
                }
            }
            if(flag==1) count += str.size();
        }
        return count;
    }
};