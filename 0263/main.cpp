class Solution {
public:
    bool isUgly(int num) {
        if(num<=0) return false;
        while(num%2==0) num /= 2;  // while((num&1)==0) num>>=1;
        while(num%3==0) num /= 3;
        while(num%5==0) num /= 5;
        return num == 1;
// return num > 0 and 3**20 * 2**31 * 5**14 % num == 0
    }
};