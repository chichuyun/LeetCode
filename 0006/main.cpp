class Solution {
public:
    string convert(string s, int numRows) {
        if(s.size() <= numRows || numRows==1) return s;
        ostringstream ss;
        int len = s.size();
        int num = 2*numRows - 2;
        
        for(int i=0; i<len; i+=num) ss << s[i];  // top
        
        int j = 1;
        for(int k=0; k<numRows-2; ++k) {
            for(int i=0; i<len; i+=num) {
                if(i+j < len) ss << s[i+j];
                if(i+num-j < len) ss << s[i+num-j];
            }
            ++j;
        }

        for(int i=numRows-1; i<len; i+=num) ss << s[i]; // bottom

        return ss.str();
    }
};