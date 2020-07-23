class Solution {
public:
    bool isStrobogrammatic(string num) {
        if(num.empty()) return true;
        int len = num.size();
        if(len%2==1 && (num[len/2]!='8' && num[len/2]!='1' && num[len/2]!='0')) return false;  // odd

        int l = 0, r = num.size()-1;
        while(l < r) {
            if(!((num[l]=='0' && num[r]=='0') ||
                 (num[l]=='1' && num[r]=='1') ||
                 (num[l]=='8' && num[r]=='8') ||
                 (num[l]=='6' && num[r]=='9') ||
                 (num[l]=='9' && num[r]=='6')))
                 return false;
            ++l;
            --r;
        }

        return true;
    }
};