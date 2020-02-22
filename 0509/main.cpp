class Solution {
public:
    unordered_map<int,int> dict;
    int fib(int N) {
        if(N<=0) {
            return 0;
        }
        else if (N<=2) {
            return 1;
        } else {
            if(dict.find(N-2) == dict.end()) { dict[N-2] = fib(N-2); }
            if(dict.find(N-1) == dict.end()) { dict[N-1] = fib(N-1); }
            
            return dict[N-1] + dict[N-2];
        }
            
    }
};