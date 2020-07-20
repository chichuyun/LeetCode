class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1.empty()) return num2;
        if(num2.empty()) return num1;

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
       
        int n, m, con=0;
        ostringstream str;
        int i = 0, j = 0;
        while(i < num1.size() || j < num2.size()) {
            if(i < num1.size()) {
                n = num1[i] - '0';
                ++i;
            } else {
                n = 0;
            }
            if(j < num2.size()) {
                m = num2[j] - '0';
                ++j;
            } else {
                m = 0;
            }
            
            str << (n + m + con)%10;
            con = (n + m + con)/10;
        }
        if(con == 1) {
            str << 1;
        }

        string res = str.str();
        reverse(res.begin(), res.end());

        return res;
    }
};