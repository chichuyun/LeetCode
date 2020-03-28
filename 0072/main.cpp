class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size();
        vector<vector<int>> nums(len1+1, vector<int>(len2+1));
        for(int i=0;i<=len1;++i) nums[i][0] = i;
        for(int j=0;j<=len2;++j) nums[0][j] = j;
        for(int i=1;i<=len1;++i) {
            for(int j=1;j<=len2;++j) {
                if(word1[i-1]==word2[j-1]) {
                    nums[i][j] = nums[i-1][j-1];
                } else {
                    nums[i][j] = 1 + min(nums[i-1][j-1],min(nums[i][j-1],nums[i-1][j]));
                }
            }
        }
        return nums[len1][len2];
    }
};

/* time out
class Solution {
private:
    void replace(string word1, string& word2, int n, int& count, int num) {
        word1[n] = word2[n];
        helper(word1, word2, n+1, count, num);
    }

    void remove(string word1, string& word2, int n, int& count, int num) {
        word1.erase(n,1);
        helper(word1, word2, n, count, num);
    }

    void insert(string word1, string& word2, int n, int& count, int num) {
        word1.insert(n,1,word2[n]);
        helper(word1, word2, n, count, num);
    }

    void helper(string& word1, string& word2, int n, int& count, int num) {
        if(num >= count) return;
        if(word1 == word2) {
            count = min(count, num);
            return;
        }
        int len = min(word1.size(), word2.size());
        while(n < len && word1[n]==word2[n]) ++n;
        ++num;
        if(n < len) replace(word1, word2, n, count, num);
        if(n < len || word1.size()>word2.size()) remove(word1, word2, n, count, num);
        if(n < len || word1.size()<word2.size()) insert(word1, word2, n, count, num);
    }

public:
    int minDistance(string word1, string word2) {
        int count = max(word1.size(),word2.size());
        helper(word1, word2, 0, count, 0);
        return count;
    }
};
*/