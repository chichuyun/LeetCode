/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int res = 0;
        for(int i=1; i<n; ++i) {
            if(knows(res, i)) res = i;
        }

        for(int i=0; i<n; ++i) {
            if(res!=i && (!knows(i,res) || knows(res,i))) {
                return -1;
            }
        }

        return res;
    }
};