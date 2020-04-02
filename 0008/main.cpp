class Solution {
public:
    int myAtoi(string str) {
        ostringstream num;
        int n=0, sign=1;
        while(n < str.size() && str[n]==' ') ++n;
        if(n < str.size() && (str[n]=='-' || str[n]=='+')) {
            if(str[n]=='+') {sign = +1;}
            if(str[n]=='-') {sign = -1;}
            ++n;
        }
        while(n < str.size() && str[n]=='0') ++n;
        for(int i=n;i<str.size();++i) {
            if(str[i]>='0' && str[i]<='9') {
                num<<str[i];
            } else {
                break;
            }
        }
        if(num.str().empty()) return 0;
        if(sign==1) {
            if(num.str().size()>10) return INT_MAX;
            if(num.str().size()==10 && num.str()>"2147483647") return INT_MAX;
            return stoi(num.str());
        }
        if(sign==-1) {
            if(num.str().size()>10) return INT_MIN;
            if(num.str().size()==10 && num.str()>"2147483648") return INT_MIN;
            return stoi('-'+num.str());
        }
        return 0;
    }
};