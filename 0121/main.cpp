class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;

        int max=0, p=prices[0];
        for(int price:prices) {
            p = price>p ? p : price;
            max = max > price-p ? max : price-p;
        }
        return max;
    }
};