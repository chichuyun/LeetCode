class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int num=0;
        unordered_map<char,int> counts;
        for(int i=0;i<J.size();++i) counts[J[i]] = 0;
        
        for(int i=0;i<S.size();++i) {
            if(counts.find(S[i])!=counts.end()) {
                ++counts[S[i]];
            }
        }
        for(auto is=counts.begin();is!=counts.end();++is) num+=is->second;
        return num;
    }
};