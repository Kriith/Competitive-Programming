class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int n = matrix[0].size(), l = 0, r = matrix.size()*n - 1;
            while(l <= r){
                int mid = (r - l)/2 + l;
                int i = mid/n, j = mid%n;
                if(matrix[i][j] == target) return true;
                else if(matrix[i][j] > target) r = mid - 1;
                else l = mid + 1;
            }
            return false;
        }
    };