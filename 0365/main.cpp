class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(x==z || y==z || x+y==z) return true;
        if(x+y<z) return false;
        if(x>y) swap(x,y);
        if(x==0) {
            if(y==z) {
                return true;
            } else {
                return false;
            }
        }
        unordered_set<int> nums;

        int n=y, base=0;   // base=0 and base=x are same.
        while(base!=x) {
            base = (n/x + 1)*x - n;
            if((z-base)%x==0) return true;
            n = y - base;
        }
        return false;
    }
};