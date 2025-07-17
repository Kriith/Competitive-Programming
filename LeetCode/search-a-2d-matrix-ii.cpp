class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(), l = m - 1, r = 0;
        while(l >= 0 && r < n){
            if(matrix[l][r] == target) return true;
            if(matrix[l][r] > target) l--;
            else r++;
        }
        return false;
    }
};