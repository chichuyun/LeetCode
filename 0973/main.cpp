typedef vector<int> pairs;
struct great {
    bool operator()(pairs p, pairs q) {
        return (float)p[0]*p[0] + (float)p[1]*p[1] > 
               (float)q[0]*q[0] + (float)q[1]*q[1];
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pairs,vector<pairs>,great> nums;
        for(auto p : points) nums.emplace(p);
        vector<vector<int>> res;
        for(int i=0;i<K;++i) {
            res.push_back(nums.top());
            nums.pop();
        }
        return res;
    }
};

/*
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
      nth_element(points.begin(),points.begin()+K,points.end(),[](const vector<int>&v1,const vector<int> &v2){
          return v1[0]*v1[0]+v1[1]*v1[1]<v2[0]*v2[0]+v2[1]*v2[1];
      });
      return vector<vector<int>>(points.begin(),points.begin()+K);
    }
};
*/