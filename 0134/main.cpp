class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int count=0, current=0, start=0;
        for(int i=0;i<gas.size();++i) {
            count += gas[i] - cost[i];
            current += gas[i] - cost[i];
            if(current < 0) {
                start = i + 1;
                current = 0;
            }
        }
        return count < 0 ? -1 : start;
/*
        int count=0, len=gas.size(), flag;
        for(int i=0;i<len;++i) {
            gas[i] -= cost[i];
            count += gas[i];
        }
        if(count < 0) return -1;
        for(int i=0;i<len;++i) {
            if(gas[i]>=0) {
                count = len;
                int left=i, num=gas[i];
                flag = 1;
                while(--count) {
                    left = min(left+1, len-1);
                    num += gas[left];
                    if(num < 0) flag=0;
                }
                if(flag) return i;
            }
        }
        return -1;
*/
    }
};