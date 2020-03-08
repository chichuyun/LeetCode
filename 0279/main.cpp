class Solution {
public:
    int numSquares(int n) {
        queue<int> nums;
        int max=(int)sqrt(n);
        int count=0, num, c1, c2;
        
        nums.push(n);
        c2 = 1;
        while(true) {
            ++count;
            c1 = c2;
            c2 = 0;
            while(c1) {
                n = nums.front();
                nums.pop();
                for(int i=1;i<=max;++i) {
                    num = n - i*i;
                    if(num==0) {
                        return count;
                    } else if(num>0) {
                        ++c2;
                        nums.push(num);
                    } else {
                        break;
                    }
                }
                --c1;
            }

        }
        return count;
/* A positive integer can definitely be expressed as the sum of the squares of four or less numbers.
        while (n % 4 == 0) n /= 4;
        if (n % 8 == 7) return 4;
        for (int a = 0; a * a <= n; ++a) {
            int b = sqrt(n - a * a);
            if (a * a + b * b == n) {
                return !!a + !!b;
            }
        }
        return 3;
*/
    }
};