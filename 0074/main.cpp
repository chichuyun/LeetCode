class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0 || matrix[0].size()==0) return false;
        int cols=matrix.size()-1, rows=matrix[0].size()-1;
        if(matrix[0][0]>target || matrix[cols][rows]<target) return false;

        int left, right, mid, mid2;
        left = 0;
        right = cols;
        while(left <= right) {
            mid = left + (right-left);
            if(matrix[mid][0]==target) {
                return true;
            } else if(matrix[mid][0]>target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        left = 0;
        right = rows;
        while(left <= right) {
            mid2 = left + (right-left);
            if(matrix[mid][mid2]==target) {
                return true;
            } else if(matrix[mid][mid2]>target) {
                right = mid2 - 1;
            } else {
                left = mid2 + 1;
            }
        }
        return false;
/* another method (throgh mod)
        if(matrix.size()==0||matrix[0].size()==0)return false;
        int m = matrix[0].size();
        int n = matrix.size();
        int left = 0;
        int right = m*n-1;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(matrix[mid/m][mid%m]==target){
                return true;
            }else if(matrix[mid/m][mid%m]>target){
                right = mid-1;
            }else if(matrix[mid/m][mid%m]<target){
                left = mid+1;
            }
        }
        return false;
*/
    }
};