using namespace std::placeholders;

class Solution {
private:
    vector<int> point;
    static int _distance(vector<int>& p, vector<int>& q) {
        return (p[0] - q[0])*(p[0] - q[0]) + 
               (p[1] - q[1])*(p[1] - q[1]);
    }

    static int _cross(vector<int>& p, vector<int>& q, vector<int>& r) {
        // p -> q -> r
        // (r - q) `cross` (q - p)
        return (q[0] - p[0])*(r[1] - q[1]) -
               (q[1] - p[1])*(r[0] - q[0]);
    }

    static bool _func_l(vector<int>& p, vector<int>& q, vector<int>& point) {
        int cross = _cross(point, p, q);
        if(cross != 0) return cross > 0;
        if(p[0] > point[0]) {
            return _distance(p, point) < _distance(q, point);
        } else {
            return _distance(p, point) > _distance(q, point);
        }
    }

    static bool _func_r(vector<int>& p, vector<int>& q, vector<int>& point) {
        int cross = _cross(point, p, q);
        if(cross != 0) return cross > 0;
        if(p[0] >= point[0]) {
            return _distance(p, point) < _distance(q, point);
        } else {
            return _distance(p, point) > _distance(q, point);
        }
    }
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& points) {
        if(points.size() < 4) return points;
        vector<vector<int>> res;
        point.resize(2); // left bottom point
        point[0] = INT_MAX; point[1] = INT_MAX;
        
        int right = INT_MIN;
        int len = points.size(), index = 0;
        for(int i=0; i<points.size(); ++i) {
            auto &p = points[i];
            right = max(right, p[0]);
            if(p[1] < point[1] || (p[1] == point[1] && p[0] < point[0])) {
                point = p;
                index = i;
            }
        }
        
        auto __func_r = bind(_func_r, _1, _2, point);
        auto __func_l = bind(_func_l, _1, _2, point);

        swap(points[0], points[index]);  // move point to points[0]
        if(point[0] == right) {
            sort(points.begin()+1, points.end(), __func_r);
        } else {
            sort(points.begin()+1, points.end(), __func_l);
        }

        int cross;
        stack<vector<int>> nodes;
        nodes.push(points[0]);
        nodes.push(points[1]);
        for(int i=2; i<points.size(); ++i) {
            vector<int> top = nodes.top();
            nodes.pop();
            cross = _cross(nodes.top(), top, points[i]);

            if(cross < 0) {
                while(true) {
                    top = nodes.top();
                    nodes.pop();
                    cross = _cross(nodes.top(), top, points[i]);
                    if(cross >= 0) break;
                }
            }
            nodes.push(top);
            nodes.push(points[i]);
        }

        while(!nodes.empty()) {
            res.push_back(nodes.top());
            nodes.pop();
        }

        return res;
    }
};