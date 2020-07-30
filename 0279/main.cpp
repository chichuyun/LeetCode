class Solution {
public:
    int numSquares(int n) {
        int count=0, num, m;
        
        queue<int> nums;
        nums.push(n);
        while(true) { // BFS
            ++count;
            m = nums.size();
            while(m--) {
                n = nums.front();
                nums.pop();
                for(int i=1;i*i<=n;++i) {
                    num = n - i*i;
                    if(num==0) {
                        return count;
                    } else {
                        nums.push(num);
                    }
                }
            }
        }
        return count;
    }
};
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