#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sp " "

int mod = 1e9+7;

void solve(){
    int n, m;
    cin>>n>>m;
    vector<int> x(n);
    for(int i = 0; i < n; i++) cin>>x[i];

    vector<vector<int>> dp(n, vector<int>(m+1, 0));
    if(x[0] == 0) fill(dp[0].begin(), dp[0].end(), 1);
    else dp[0][x[0]] = 1;

    for(int i = 1; i < n; i++){
        if(x[i]){
            for(int y: {x[i] - 1, x[i], x[i] + 1})
                if(y > 0 && y <= m)
                (dp[i][x[i]] += dp[i-1][y]) %= mod;
            }
            else{
                for(int j = 1; j <= m; j++){
                    for(int k : {j-1, j, j+1})
                        if(k > 0 && k <= m)
                            (dp[i][j] += dp[i-1][k]) %= mod;
            }
        }
    }
    for(int i = 1; i < m; i++)
        (dp[n-1][m] += dp[n-1][i]) %= mod;
    cout<<dp[n-1][m];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("C:/Users/HP/Desktop/Competitive Programming/input.txt", "r", stdin);
    freopen("C:/Users/HP/Desktop/Competitive Programming/output.txt", "w", stdout);
#endif
    ll t = 1;
    // cin>>t; 
    while(t--)
        solve();
    return 0;
}