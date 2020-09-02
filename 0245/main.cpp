class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int countMin = words.size();
        if(word1 != word2) {
            int ip1 = -1, ip2 = -1;
            for(int i=0; i<words.size(); ++i) {
                if(word1 == words[i]) {
                    ip1 = i;
                } else if(word2 == words[i]) {
                    ip2 = i;
                }
                if(ip1 != -1 && ip2 != -1) {
                    countMin = min(countMin, abs(ip1-ip2));
                }
            }
        } else {
            int pre = -1;
            for(int i=0; i<words.size(); ++i) {
                if(words[i]==word1) {
                    if(pre != -1) {
                        countMin = min(countMin, (i-pre));
                    }
                    pre = i;
                }
            }
        }

        return countMin;
    }
};