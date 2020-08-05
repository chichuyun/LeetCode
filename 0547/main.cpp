class Solution {
private:
    vector<int> parents, sizes;
    int count;
    void initialize(int len) {
        parents.resize(len);
        sizes.resize(len);
        count = len;
        for(int i=0; i<len; ++i) {
            sizes[i] = 1;
            parents[i] = i;
        }
    }

    void unions(int i, int j) {
        int rooti = find(i);  // find root of i
        int rootj = find(j);
        if(rooti == rootj) return;  // if is connected
        if(sizes[rooti] > sizes[rootj]) {
            parents[rootj] = rooti;
            sizes[rootj] += sizes[rooti];
        } else {
            parents[rooti] = rootj;
            sizes[rooti] += sizes[rootj];
        }
        --count;
    }

    int find(int i) {
        while(i != parents[i]) {   // because root of root equal to root
            parents[i] = parents[parents[i]];  // 
            i = parents[i];
        }
        return i;
    }
public:
    int findCircleNum(vector<vector<int>>& M) {
        int len = M.size();
        initialize(len);
        
        for(int i=0; i<len; ++i) {
            for(int j=0; j<i; ++j) {
                if(M[i][j]==1) unions(i, j);
            }
        }
        return count;
    }
};