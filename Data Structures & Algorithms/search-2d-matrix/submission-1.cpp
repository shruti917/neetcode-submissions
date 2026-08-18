class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row= matrix.size();
        int col= matrix[0].size();

        int l=0, r= row*col-1;
        while(l<=r){
            int mid= l+(r-l)/2;
            int ro= mid/col; int co= mid%col;
            if(matrix[ro][co] < target){
l=mid+1;
            }
            else if(matrix[ro][co] > target){
r= mid-1;
            }
            else return true;
        }
        return false;
    }
};
