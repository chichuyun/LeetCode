class WordDistance {
private:
    unordered_map<string, vector<int>> maps;
public:
    WordDistance(vector<string>& words) {
        for(int i=0; i<words.size(); ++i) {
            maps[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        vector<int>& nums1 = maps[word1];
        vector<int>& nums2 = maps[word2];

        int countMin = INT_MAX;
        int i = 0, j = 0;
        int len1 = nums1.size(), len2 = nums2.size();
        while(i < len1 && j < len2) {
            if(nums1[i] >= nums2[j]) {
                countMin = min(countMin, nums1[i]-nums2[j]);
                ++j;
            } else {
                countMin = min(countMin, nums2[j]-nums1[i]);
                ++i;
            }
        }
        return countMin;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */