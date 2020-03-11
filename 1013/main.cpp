class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        if(A.size()<3) return false;
        int sumleft=0, sumright=0, total=0;
        
        total = accumulate(A.begin(),A.end(),0);
        if(total%3) return false;
        total = total/3;
        for(int i=0;i<A.size()-2;++i) {
            sumleft += A[i];
            if(sumleft==total) {
                for(int j=A.size()-1;j>i+1;--j) {
                    sumright += A[j];
                    if(sumright==total) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};