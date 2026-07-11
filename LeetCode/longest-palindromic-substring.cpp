//O(n^2) DP solution
class Solution {
public:
    string longestPalindrome(string s) {
        int currLen = 2, ansLen = 1, ansIndex = 0, n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, 0));
        for(int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        while(currLen <= n) {
            for(int i = 0; i <= n - currLen; i++) {
                // cout<<i<<" "<<s[i]<<' '<<currLen<<' '<<s[i+currLen]<<endl;
                int j = i + currLen - 1;
                if(s[i] == s[j]) {
                    if(currLen > 3) {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                    else {
                        dp[i][j] = 1;
                    }
                    if(dp[i][j]) {
                        ansLen = currLen;
                        ansIndex = i;
                    }
                }
            }
            currLen ++;
        }
        return s.substr(ansIndex, ansLen);
    }
};

//O(n) solution, 