class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        k = min(k, (int)arr.size());
        
        deque<int> nums;
        for(int i=0; i<arr.size(); ++i) {
            nums.push_back(arr[i]);
        }
        
        int count = 0;
        int num1, num2, l, m;
        for(int i=0; i<arr.size(); ++i) {
            num1 = nums.front();
            nums.pop_front();
            num2 = nums.front();
            nums.pop_front();
            
            l = min(num1, num2);
            m = max(num1, num2);
            
            if(m == num1) {
                ++count;
            } else {
                count = 1;
            }
            
            if(count == k) break;
            nums.push_front(m);
        }
        
        return m;
    }
};