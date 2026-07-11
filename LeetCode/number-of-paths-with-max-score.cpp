class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<int> pathsWithMaxScore(vector<string>& board) {
        int h = board.size(), w = board[0].size();
        vector<vector<int>> dp(w, vector<int>(2, 0)), prev(w, vector<int>(2, 0));
        for(int i = h - 1; i >= 0; i--) {
            for(int j = w - 1; j >= 0; j--) {
                cout<<i<<" "<<j<<" "<<dp[j][0]<<" "<<dp[j][1]<<endl;
                dp[j][0] = dp[j][1] = 0;
                if(board[i][j] == 'X') {
                    dp[j][0] = INT32_MIN;
                }
                else if(board[i][j] == 'S') {
                    dp[j][1] = 1;
                }
                else {
                    int currVal = 0;
                    if(board[i][j] != 'E') {
                        currVal = board[i][j] - '0';
                    }
                    if(i < h - 1 && dp[j][0] < prev[j][0] + currVal) {
                        cout<<1<<endl;
                        dp[j][0] = prev[j][0] + currVal;
                        dp[j][1] = prev[j][1];
                    }
                    else if(i < h - 1 && dp[j][0] == prev[j][0] + currVal) {
                        cout<<2<<" "<<dp[j][1]<<" "<<prev[j][1]<<endl;
                        dp[j][1] = (dp[j][1] + prev[j][1]) % MOD;
                    }
                    if(j < w - 1 && dp[j][0] < dp[j + 1][0] + currVal) {
                        cout<<3<<endl;
                        dp[j][0] = dp[j + 1][0] + currVal;
                        dp[j][1] = dp[j + 1][1];
                    }
                    else if(j < w - 1 && dp[j][0] == dp[j + 1][0] + currVal) {
                        cout<<4<<" "<<dp[j][1]<<" "<<dp[j + 1][1]<<endl;
                        dp[j][1] = (dp[j][1] + dp[j + 1][1]) % MOD;
                    }
                    if(i < h - 1 && j < w - 1 && dp[j][0] < prev[j + 1][0] + currVal) {
                        cout<<5<<endl;
                        dp[j][0] = prev[j + 1][0] + currVal;
                        dp[j][1] = prev[j + 1][1];
                    }
                    else if(i < h - 1 && j < w - 1 && dp[j][0] == prev[j + 1][0] + currVal) {
                        cout<<6<<endl;
                        dp[j][1] = (dp[j][1] + prev[j + 1][1]) % MOD;
                    }
                }
                cout<<i<<" "<<j<<" "<<dp[j][0]<<" "<<dp[j][1]<<endl;
            }
            prev = dp;
        }
        if(dp[0][0] < 0 || dp[0][1] <= 0)
            return {0, 0};
        return dp[0];
    }
};