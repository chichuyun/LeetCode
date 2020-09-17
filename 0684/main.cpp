class Solution {
private:
    vector<int> ranks;
    vector<int> parents;

    bool _union(int i, int j) {
        int root_i = _find(i);
        int root_j = _find(j);
        if(root_i == root_j) return true;

        if(ranks[root_i] > ranks[root_j]) {
            parents[root_j] = root_i;
            ranks[root_i] += ranks[root_j];
        } else {
            parents[root_i] = root_j;
            ranks[root_j] += ranks[root_i];
        }
        return false;
    }

    int _find(int i) {
        if(i != parents[i]) {
            parents[i] = _find(parents[i]);
        }
        return parents[i];
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int N = edges.size();
        ranks.resize(N+1);
        parents.resize(N+1);
        for(int i=1; i<=N; ++i) ranks[i] = 1;
        for(int i=1; i<=N; ++i) parents[i] = i;
        
        vector<int> res;
        for(auto& edge : edges) {
            if(_union(edge[0], edge[1])) {
                res = edge;
            }
        }
        return res;
    }
};