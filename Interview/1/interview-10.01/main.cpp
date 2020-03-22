class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int len=A.size(), lenB=B.size(), lenA=len-lenB;
        int i=lenA-1, j=lenB-1;
        for(int k=len-1;k>=0;--k) {
            if(i>=0 && j>=0) {
                if(A[i]>B[j]) {
                    A[k] = A[i];
                    --i;
                } else {
                    A[k] = B[j];
                    --j;
                }
            } else if(i>=0) {
                A[k] = A[i];
                --i;
            } else {
                A[k] = B[j];
                --j;
            }
        }
    }
};