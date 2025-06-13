//o(n^2) mem
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(triangle);
        for(int i = 1; i < n; i++){
            for(int j = 0; j <= i; j++){
                int t = INT_MAX;
                if(j > 0) t = min(t, dp[i-1][j-1]);
                if(j < i) t = min(t, dp[i-1][j]);
                dp[i][j] += t;
            }
        }
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};

//o(n) mem
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> v;
        v = triangle[0];
        for(int i = 1; i < n; i++){
            vector<int> t = triangle[i];
            for(int j = 0; j <= i; j++){
                int temp = INT_MAX;
                if(j > 0) temp = min(temp, v[j-1]);
                if(j < i) temp = min(temp, v[j]);
                t[j] += temp;
            }
            v = t;
        }
        return *min_element(v.begin(), v.end());
    }
};