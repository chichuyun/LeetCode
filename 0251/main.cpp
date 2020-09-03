class Vector2D {
private:
    int count;
    int len, index, i;
    vector<vector<int>> nums;
public:
    Vector2D(vector<vector<int>>& v) {
        count = 0;
        index = 0;
        i = 0;
        len = 0;
        for(auto& vec : v) len += vec.size();
        nums = v;
    }
    
    int next() {
        while(i == nums[index].size()) {
            i = 0;
            ++index;
        }
        
        int n = nums[index][i];
        ++i;
        ++count;
        return n;
    }
    
    bool hasNext() {
        return count < len;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */