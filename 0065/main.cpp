class Solution {
public:
    bool isNumber(string s) {
        int ie=0, idot=0, n=0, m=s.size()-1;
        int flag1=1, flag2=1, flag3=1, isign=0;
        while(n < s.size() && s[n]==' ') ++n;   // remove left ' '
        if(n==s.size()) return false; // no num;
        while(m >=0 && s[m]==' ') --m;
        while(ie <= m && s[ie]!='e') ++ie;  // find e, split one num to two num.
        if(ie==m && s[m]=='e') return false;  // e without right num
        if(ie==n && s[n]=='e') return false;  // e without left num
        if(n <= m && (s[n]=='+' || s[n]=='-')) ++n; // get left sign
        idot = n;
        while(idot < ie && s[idot]!='.') ++idot;
        for(int i=n;i<idot;++i) {    // left num left part
            if(s[i]>'9' || s[i]<'0') return false;
            flag1 = 0;
        }
        ++idot;  // sign
        for(int i=idot;i<ie;++i) {    // left num right part
            if(s[i]>'9' || s[i]<'0') return false;
            flag2 = 0;
        }
        if(flag1+flag2>1) return false;
        ++ie;  // sign
        if(ie <= m && (s[ie]=='+' || s[ie]=='-')) {++ie; isign=1;} // get right sign
        for(int i=ie;i<=m;++i) {    // right num
            if(s[i]>'9' || s[i]<'0') return false;
            flag3 = 0;
        }
        if(isign && flag3) return false;
        return true;
    }
};

/*
class Solution {
public:
    int transfer[9][6] = {{0, 1, 6, 2, -1},
                          {-1, -1, 6, 2, -1},
                          {-1, -1, 3, -1, -1},
                          {8, -1, 3, -1, 4},
                          {-1, 7, 5, -1, -1},
                          {8, -1, 5, -1, -1},
                          {8, -1, 6, 3, 4},
                          {-1, -1, 5, -1, -1},
                          {8, -1, -1, -1, -1}};

    int final_state = 0b101101000;

    int make(char c) {
        switch (c) {
        case ' ':
            return 0;
        case '+':
        case '-':
            return 1;
        case '.':
            return 3;
        case 'e':
            return 4;
        default:
            if (c >= 48 && c <= 57)
                return 2;
        }
        return -1;
    }

    bool isNumber(string s) {
        int state = 0;
        for (char &c : s) {
            int id = make(c);
            if (id < 0)
                return false;
            state = transfer[state][id];
            if (state == -1)
                return false;
        }
        return (final_state & (1 << state)) > 0;
    }
};
*/