class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        if(seqs.empty()) return false;
        int N = org.size();
        vector<unordered_set<int>> adjs(N);
        vector<int> indegrees(N, 0);
        for(int i=0; i<seqs.size(); ++i) {
            if(seqs[i][0] < 1 || seqs[i][0] > N) return false;
            for(int j=0; j<seqs[i].size()-1; ++j) {
                if(seqs[i][j+1] < 1 || seqs[i][j+1] > N) return false;
                adjs[seqs[i][j]-1].insert(seqs[i][j+1]-1);
            }
        }
        
        for(int i=0; i<N; ++i) {
            for(int j : adjs[i]) {
                indegrees[j]++;
            }
        }

        if(indegrees[org[0]-1] != 0) return false;
        for(int i=1; i<N; ++i) {
            if(indegrees[org[i]-1] < 1) return false;
        }
        
        int count = 0;
        queue<int> nodes;
        for(int i=0; i<N; ++i) {
            if(indegrees[i]==0) nodes.push(i);
        }

        while(!nodes.empty()) {
            if(nodes.size() > 1) return false;
            int index = nodes.front();
            nodes.pop();
            
            cout << org[count] << " " << index << endl;
            if(org[count]-1!=index) return false;
            ++count;
            for(int j : adjs[index]) {
                indegrees[j]--;
                if(indegrees[j]==0) nodes.push(j);
            }
        }

        return count == N;
    }
};