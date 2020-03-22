class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (x+y < z) return false;
        if (x==0 || y==0) return z==0 || x+y==z;
        if(x>y) swap(x,y);

        int n=y, base=0;   // base=0 and base=x are same.
        while(base!=x) {
            base = (n/x + 1)*x - n;
            if((z-base)%x==0) return true;
            n = y - base;
        }
        return false;

//      return z % gcd(x, y) == 0;

    }
};