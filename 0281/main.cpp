class ZigzagIterator {
private:
    int len1, len2, len, minlen;
    int count;
    vector<int>::iterator iter1, iter2;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        len1 = v1.size();
        len2 = v2.size();
        len = len1 + len2;
        minlen = min(len1, len2)*2;
        count = 0;
        iter1 = v1.begin();
        iter2 = v2.begin();
    }

    int next() {
        
        int res;
        if(count < minlen) {
            if(count%2) {
                res = *iter2;
                ++iter2;
            } else {
                res = *iter1;
                ++iter1;
            }
        } else {
            if(len1 < len2) {
                res = *iter2;
                ++iter2;
            } else {
                res = *iter1;
                ++iter1;
            }
        }
        ++count;
        return res;
    }

    bool hasNext() {
        return count < len;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */