class Solution {
private:
    const int mod = 1e9 + 7;
public:
    int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) {
        if(staple.empty() || drinks.empty()) return 0;
        sort(staple.begin(), staple.end());
        sort(drinks.begin(), drinks.end());
        
        int count = 0, index = drinks.size()-1;
        for(int& s : staple) {
            int n = x - s;
            if(n < drinks[0]) break;
            while(index >= 0 && drinks[index] > n) --index;
            count += index + 1;
            count %= mod;
        }
        return count;
    }
};