class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> v(n);
        v = matrix[0];
        for(int i = 1; i < n; i++){
            vector<int> t = matrix[i];
            for(int j = 0; j < n; j++){
                int temp = v[j];
                if(j > 0) temp = min(temp, v[j-1]);
                if(j < n-1) temp = min(temp, v[j+1]);
                t[j] += temp;
            }
            v = t;
        }
        return *min_element(v.begin(), v.end());
    }
};