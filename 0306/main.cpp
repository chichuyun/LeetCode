class Solution {
private:
    string add(string num1, string num2) {
        ostringstream num;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int len1 = num1.size(), len2 = num2.size();
        int con = 0, i = 0, j = 0, n1, n2, n;
        while(i < len1 || j < len2) {
            n1 = 0;
            n2 = 0;
            if(i < len1) {
                n1 = num1[i] - '0';
                ++i;
            }
            if(j < len2) {
                n2 = num2[j] - '0';
                ++j;
            }
            n = n1 + n2 + con;
            con = n/10;
            n = n%10;
            num << n;
        } 
        if(con == 1) num << 1;
        string res = num.str();
        reverse(res.begin(), res.end());
        return res;
    }
public:
    bool isAdditiveNumber(string num) {
        int len = num.size(), len3, len2, len1;
        string num1, num2, num3;
        bool flag;

        for(int i=1; i<len; ++i) {
            for(int j=1; j<len; ++j) {
                len1 = i;
                len2 = j;
                if(len1 + len2 > len) break;
                flag = true;
                num1 = num.substr(0, len1);
                num2 = num.substr(i, len2);
                if((len1!=1 && num1[0]=='0') || (len2!=1 && num2[0]=='0')) break;
                int k = len1 + len2;
                while(k < len) {
                    num3 = add(num1, num2);
                    len3 = num3.size();
                    if(num.substr(k, len3)!=num3) {
                        if(k+len3 > len)  flag = false;
                        break;
                    }
                    if(k+len3 == len) return true;
                    num1 = num2; len1 = len2;
                    num2 = num3; len2 = len3;
                    k += len3;
                }
                if(!flag) break;
            }
        }
        return false;
    }
};