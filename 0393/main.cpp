class Solution {
private:
    inline bool isZero(int& a)  { return ~a & 0b10000000; }
    inline bool isOne(int& a)   { return ~a & 0b01000000 && a & 0b10000000; }
    inline bool isTwo(int& a)   { return ~a & 0b00100000 && (a & 0b11000000) == 0b11000000; }
    inline bool isThree(int& a) { return ~a & 0b00010000 && (a & 0b11100000) == 0b11100000; }
    inline bool isFour(int& a)  { return ~a & 0b00001000 && (a & 0b11110000) == 0b11110000; }
public:
    bool validUtf8(vector<int>& data) {
        int i = 0, j = 0;
        while(i < data.size()) {
            if(isFour(data[i])) {
                j = i + 1;
                i += 4;
                if(i > data.size()) return false;
                for(int k=j;k<i;++k) {
                    if(!isOne(data[k])) return false;
                }
            } else if(isThree(data[i])) {
                j = i + 1;
                i += 3;
                if(i > data.size()) return false;
                for(int k=j;k<i;++k) {
                    if(!isOne(data[k])) return false;
                }
            } else if(isTwo(data[i])) {
                j = i + 1;
                i += 2;
                if(i > data.size()) return false;
                for(int k=j;k<i;++k) {
                    if(!isOne(data[k])) return false;
                }
            } else if(isZero(data[i])) {
                ++i;
            } else {
                return false;
            }
        }
        return true;
    }
};