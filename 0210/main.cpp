class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses);
        vector<vector<int>> adjacency(numCourses);
        for(auto& p : prerequisites) {
            ++inDegree[p[0]];
            adjacency[p[1]].push_back(p[0]);
        }

        vector<int> res;
        queue<int> nodes;
        for(int i=0;i<numCourses;++i) {
            if(inDegree[i]==0) nodes.push(i);
        }

        while(!nodes.empty()) {
            int n = nodes.front();
            nodes.pop();
            res.push_back(n);
            for(int& m : adjacency[n]) {
                --inDegree[m];
                if(inDegree[m]==0) nodes.push(m);
            }
        }
        return res.size() == numCourses ? res : vector<int>();
    }
};