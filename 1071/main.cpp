class Solution {
public:

    inline int gcd(int a, int b) {return b == 0? a : gcd(b , a % b);}
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) return "";
        return str1.substr(0, gcd(str1.size(), str2.size()));
    }
/*
private:
    string mod(string str1, string str2) {
        int i, len=str1.size()/str2.size();
        while(len) {
            for(int j=0;j<str2.size();++j) {
                if(str1[i]!=str2[j]) {
                    return "null";
                }
                ++i;
            }
            --len;
        }
        return str1.substr(i,str1.size()%str2.size());
    }
public:
    string gcdOfStrings(string str1, string str2) {
        string mid;
        if(str1.size()<str2.size()) {
            string temp = str1;
            str1 = str2;
            str2 = temp;
        }
        
        mid = mod(str1, str2);
        if(mid.empty()) {
            return str2;
        } else if(mid=="null") {
            return "";
        } else {
            return gcdOfStrings(str2, mid);
        }
        return "";
    }
*/

};