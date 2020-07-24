class Solution {
public:
    bool rotateString(string A, string B) {
        if(A.size() != B.size()) return false;
        if(A == B) return true;

        vector<int> pos;

        for(int i=0; i<A.size(); ++i) {
            if(A[i] == B[0]) pos.push_back(i);
        }
        
        bool flag = true;
        int len = A.size();
        for(auto& p : pos) {
            flag = true;
            for(int i=0; i<A.size(); ++i) {
                if(B[i]!=A[(i+p)%len]) {  // left of B
                    flag = false;
                    break;
                }
            }
            if(flag) return true;
        }

        return false;
    }
};