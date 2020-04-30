class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long numer = numerator, denom = denominator;
        if(numer==0 || denom==0) return "0";
        ostringstream str, dots;
        if(numer<0 && denom>0) {
            str<<'-';
            numer = -numer;
        } else if(numer>0 && denom<0) {
            str<<'-';
            denom = -denom;
        }
        str<<numer/denom;
        long num = numer%denom;
        if(num==0) return str.str();
        str<<'.';
        unordered_map<long,long> remainder;
        int i = 1;
        while(true) {
            num *= 10;
            dots<<num/denom;
            num = num%denom;
            if(num==0 || remainder.count(num)) break;
            remainder[num] = i;
            ++i;
        }
        if(num==0) {
            str<<dots.str();
        } else {
            int end = remainder[num];  // loop begin point
            while(end>=1 && dots.str()[end-1]==dots.str()[i-1]) {--end; --i;}
            str<<dots.str().substr(0, end);
            str<<'(';
            str<<dots.str().substr(end,i-end);
            str<<')';
        }
        return str.str();
    }
};