class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<pair<int,int>> nums;
        vector<int> res(T.size(),0);
        
        nums.push(make_pair(T[0],0));
        for(int i=1;i<T.size();++i) {
            while(!nums.empty() && nums.top().first<T[i]) {
                res[nums.top().second] = i - nums.top().second;
                nums.pop();
            }
            nums.push(make_pair(T[i],i));
        }
        return res;
    }
};