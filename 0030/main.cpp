class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if(words.empty()) return res;

        unordered_map<string, int> strs, temp;
        int len = words[0].size();

        if(words.size()*len > s.size()) return res;
        for(string& word : words) strs[word]++;

        int count = words.size();
        int size = len*words.size();
        int end = s.size()-size;
        for(int i=0; i<=end; ++i) {
            temp = strs;
            count = words.size();
            for(int j=i; j<=i+size; j+=len) {
                string sub = s.substr(j,len);
                if(temp.count(sub)!=0 && temp[sub]>0) {
                    temp[sub]--;
                    --count;
                } else {
                    break;
                }
            }
            if(count==0) res.push_back(i);
        }
        
        return res;
    }
};