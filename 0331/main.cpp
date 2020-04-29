class Solution {
public:
    bool isValidSerialization(string preorder) {
        int nodes = 0, i = 0, len = preorder.size();
        while(i < len) {
            if(preorder[i]=='#') {
                --nodes;
                i += 2;
            } else {
                while(i < len && preorder[i]!=',') ++i;
                ++i;
                ++nodes;
            }
            if(nodes==-1 && i+1<len) return false;
        }
        return nodes == -1;
    }
};