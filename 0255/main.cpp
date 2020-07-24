class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        if(preorder.size()<2) return true;
        
        stack<int> s;
        int pre = INT_MIN;

        for(int& n : preorder) {
            if(n < pre) return false;  // right subtree element must greater than left subtree

            while(!s.empty() && n > s.top()) {  // clean out the left subtree
                pre = s.top();  // the maximum value of left subtree
                s.pop();
            }

            s.push(n);  // left
        }
        
        return true;
    }
};