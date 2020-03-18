class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> secs(10,0), gues(10,0);

        int countA=0, countB=0;
        ostringstream res;
        for(int i=0;i<guess.size();++i) {
            if(secret[i]==guess[i]) {
                ++countA;
            } else {
                ++secs[secret[i]-'0'];
                ++gues[guess[i]-'0'];
            }
        }
        
        for(int i=0;i<10;++i) {
            countB += min(secs[i],gues[i]);
        }
        res<<countA<<"A"<<countB<<"B";
        return res.str();
    }
};