class Solution {
private:
    int count;
    vector<int> ranks, parents;

    int find(int i) {
        if(parents[i] != i) parents[i] = find(parents[i]);
        return parents[i];
    }

    void unions(int i, int j) {
        int root_i = find(i), root_j = find(j);
        if(root_i == root_j) return;
        
        if(ranks[root_i] > ranks[root_j]) {
            parents[root_j] = root_i;
            ranks[root_j] += ranks[root_i];
        } else {
            parents[root_i] = root_j;
            ranks[root_i] += ranks[root_j];
        }
        --count;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(n == 0 && (edges.empty() || edges[0].empty())) return true;
        if(edges.size()+1 != n) return false;
        count = n;
        parents.resize(n); ranks.resize(n);
        for(int i=0; i<n; ++i) parents[i] = i;
        for(int i=0; i<n; ++i) ranks[i] = 1;
        for(auto edge : edges) unions(edge[0], edge[1]);

        return count == 1;
    }
};