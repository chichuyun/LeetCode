class Solution {
    string nums = "0123456789abcdef";
public:
    string toHex(int num) {
        if(num==-2147483648) return "80000000";
        if(num==0) return "0";
        ostringstream str;
        string s;
        if(num >= 0) {
            while(num) {
                str<<nums[num%16];
                num /= 16;
            }
        } else {
            num = -num - 1;
            int count=8;
            while(count--) {
                str<<nums[15-num%16];
                num /= 16;
            }
        }
        s = str.str();
        reverse(s.begin(),s.end());
        return s;
    }
};