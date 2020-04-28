class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses,0), res;
        vector<vector<int>> adjacency(numCourses);
        for(auto& p : prerequisites) {
            ++inDegree[p[1]];
            adjacency[p[0]].push_back(p[1]);
        }
        
        queue<int> nodes;
        for(int i=0;i<numCourses;++i) {
            if(inDegree[i]==0) nodes.push(i);
        }

        while(!nodes.empty()) {
            int n = nodes.front();
            res.push_back(n);
            nodes.pop();
            for(int& m : adjacency[n]) {
                --inDegree[m];
                if(inDegree[m]==0) nodes.push(m);
            }
        }

        return res.size() == numCourses;
    }
};