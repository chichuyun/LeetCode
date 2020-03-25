class Solution {
public:
    int integerBreak(int n) {
        switch(n) {
            case 2:
            return 1;
            case 3:
            return 2;
            case 4:
            return 4;
        }
        int base=n/3, con=n%3;
        if(con==1) {
            base -= 1;
            con = 4;
        } else if(con==0) {
            con = 1;
        }
        return pow(3,base)*con;
    }
};