class Solution {
private:
    vector<int> sizes, parents;
    int count;

    void initialize(int len) {
        count = len;
        sizes.resize(len);
        parents.resize(len);
        for(int i=0; i<len; ++i) {
            sizes[i] = 1;
            parents[i] = i;
        }
    }

    void unions(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if(root_i == root_j) return;

        if(sizes[root_i] > sizes[root_j]) {
            parents[root_j] = root_i;
            sizes[root_j] += sizes[root_i];
        } else {
            parents[root_i] = root_j;
            sizes[root_i] += sizes[root_j];
        }
        --count;
    }

    int find(int i) {
        if(i != parents[i]) parents[i] = find(parents[i]);
        return parents[i];
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        initialize(n);
        for(auto edge : edges) unions(edge[0], edge[1]);

        return count;
    }
};