struct Node {
    int key, val, freq;
    Node(int _key, int _val, int _freq) : key(_key), val(_val), freq(_freq) {};
};

class LFUCache {
private:
    int capacity, minFreq=1;
    unordered_map<int, list<Node>::iterator> nums; // key -> list<Node>::iterator
    unordered_map<int, list<Node>> nodes; // freq -> list<Node>
public:
    LFUCache(int _capacity) : capacity(_capacity) {}
    
    int get(int key) {
        if(capacity==0) return -1;
        if(nums.find(key)!=nums.end()) {
            auto it = nums[key];
            int val = it->val, freq = it->freq;
            nodes[freq].erase(it); // remove element from old one
            if(nodes[freq].empty()) {
                nodes.erase(freq);
                if(freq==minFreq) ++minFreq;
            }
            ++freq;
            nodes[freq].emplace_front(key, val, freq); // new one at front
            nums[key] = nodes[freq].begin();
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(capacity==0) return;
        if(nums.find(key)==nums.end()) {
            if(nums.size()==capacity) {
                Node node = nodes[minFreq].back(); // old one at back
                nums.erase(node.key);
                nodes[minFreq].pop_back();
                if(nodes[minFreq].empty()) {
                    nodes.erase(minFreq);
                }
            }
            nodes[1].emplace_front(key, value, 1);
            nums[key] = nodes[1].begin();
            minFreq = 1;
        } else {
            auto it = nums[key];
            int freq = it->freq;
            nodes[freq].erase(it); // remove element from old one
            if(nodes[freq].empty()) {
                nodes.erase(freq);
                if(freq==minFreq) ++minFreq;
            }
            ++freq;
            nodes[freq].emplace_front(key, value, freq); // new one at front
            nums[key] = nodes[freq].begin();
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */