class Solution {
private:
    unordered_map<string, vector<string>> adjs;
    unordered_map<string, unordered_map<string, int>> indegree;
    vector<string> res;
    int total;

    bool dfs(string str, int count) {
        if(count == total) {
            return true;
        } else {
            for(auto& s : adjs[str]) {
                if(indegree[str][s]!=0) {
                    indegree[str][s]--;
                    res.push_back(s);
                    if(dfs(s, count+1)) return true;
                    indegree[str][s]++;
                    res.pop_back();
                }
            }
        }
        return false;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto& ticket : tickets) {
            adjs[ticket[0]].push_back(ticket[1]);
            indegree[ticket[0]][ticket[1]]++;
        }
        for(auto& adj : adjs) sort(adj.second.begin(), adj.second.end());
        total = tickets.size();
        
        res.push_back("JFK");
        dfs("JFK", 0);

        return res;
    }
};