class LRUCache {
    int len, count=0;
    list<int> lsts;
    unordered_map<int,pair<list<int>::iterator,int>> nums;
public:
    LRUCache(int capacity) {
        len = capacity;
    }

    int get(int key) {
        if(nums.count(key)) {
            int value = nums[key].second;
//            lsts.erase(nums[key].first);
//            lsts.push_front(key);
            lsts.splice(lsts.begin(), lsts, nums[key].first);
            nums[key].first = lsts.begin();
            return value;
        }
        return -1;
    }

    void put(int key, int value) {
        if(nums.count(key)) {
//            lsts.erase(nums[key].first);
//            lsts.push_front(key);
//            nums[key] = make_pair(lsts.begin(),value);
            lsts.splice(lsts.begin(), lsts, nums[key].first);
            nums[key].first = lsts.begin();
            nums[key].second = value;
        } else if(count==len) {
            nums.erase(lsts.back());
            lsts.pop_back();
            lsts.push_front(key);
            nums[key] = make_pair(lsts.begin(),value);
        } else {
            ++count;
            lsts.push_front(key);
            nums[key] = make_pair(lsts.begin(),value);
        }
    }
};

/* time out
class LRUCache {
private:
    int len, top=0;
    vector<int> tops;
    unordered_map<int,pair<int,int>> nums;
public:
    LRUCache(int capacity) {
        len = capacity;
        tops.resize(len);
        top = 0;
    }
    
    int get(int key) {
        if(nums.count(key)) {
            int value = nums[key].second;
            int index = nums[key].first;
            for(int i=index+1;i<top;++i) {
                nums[tops[i]].first = i-1;
                tops[i-1] = tops[i];
            }
            nums[key].first = top-1;
            tops[top-1] = key;
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(nums.count(key)) {
            int index = nums[key].first;
            for(int i=index+1;i<top;++i) {
                nums[tops[i]].first = i-1;
                tops[i-1] = tops[i];
            }
            tops[top-1] = key;
            nums[key].first = top - 1;
            nums[key].second = value;
        } else if(top==len) {
            nums.erase(tops[0]);
            for(int i=1;i<top;++i) {
                nums[tops[i]].first = i-1;
                tops[i-1] = tops[i];
            }
            tops[top-1] = key;
            nums[key] = make_pair(top-1, value);
        } else {
            tops[top] = key;
            nums[key] = make_pair(top, value);
            ++top;
        }
    }
};
*/

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */