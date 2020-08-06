class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_set<char> two;
        int count = 0, max_v = 0;
        for(int i=0; i<s.size(); ++i) {
            two.insert(s[i]);
            if(two.size() <= 2) {
                ++count;
            } else {
                int j = i-2;
                while(s[j]==s[i-1]) j--;
                count = i - j;
                two.erase(s[j]);
                /*
                for(int j=i-2; j>=0; --j) {
                    if(s[j]!=s[i-1]) {
                        count = i - j;
                        two.erase(s[j]);
                        break;
                    }
                }
                */
            }
            max_v = max(max_v, count);
        }

        return max_v;
    }
};