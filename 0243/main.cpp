class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int countMax = INT_MAX;
        int in1 = -1, in2 = -1;
        for(int i=0; i<words.size(); ++i) {
            if(words[i] == word1) {
                in1 = i;
            } else if(words[i] == word2) {
                in2 = i;
            }
            if(in1!=-1 && in2 !=-1) countMax = min(countMax, abs(in1-in2));
        }


        return countMax;
    }
};