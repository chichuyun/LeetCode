class Solution {
private:
    vector<int> ranks, parents, islands;
    int count;

    int find(int i) {
        if(i != parents[i]) {
            parents[i] = find(parents[i]);
        }
        return parents[i];
    }

    void unions(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if(root_i==root_j) return;
        
        --count;
        if(ranks[root_i] > ranks[root_j]) {
            ranks[root_i] += ranks[root_j];
            parents[root_j] = root_i; 
        } else {
            ranks[root_j] += ranks[root_i];
            parents[root_i] = root_j; 
        }
    }
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        int len = m*n;
        count = 0;
        parents.resize(len);
        ranks.resize(len);
        islands.resize(len, 0);
        for(int i=0; i<len; ++i) {
            ranks[i] = 1;
            parents[i] = i;
        }

        vector<int> res;
        for(auto p : positions) {
            int i = p[0], j = p[1];
            int k = i*n + j;
            if(islands[k]==0) {
                islands[k] = 1;
                ++count;
                if(i > 0) {
                    if(islands[k-n]==1) unions(k-n,k);
                }
                if(j > 0) {
                    if(islands[k-1]==1) unions(k-1,k);
                }
                if(i < m-1) {
                    if(islands[k+n]==1) unions(k+n,k);
                }
                if(j < n-1) {
                    if(islands[k+1]==1) unions(k+1,k);
                }
            }
            res.push_back(count);
        }

        return res;
    }
};