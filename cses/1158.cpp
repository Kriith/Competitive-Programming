#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sp " "

void solve(){
    int n, x;
    cin>>n>>x;
    vector<int> h(n), s(n);
    for(int i = 0; i < n; i++)
        cin>>h[i];
    for(int i = 0; i < n; i++)
        cin>>s[i];

    // o(n*w) space complexity
    // vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
    // for(int i = 1; i <= n; i++){
    //     for(int j = 0; j <= x; j++){
    //         int pick = 0, notpick = dp[i-1][j];
    //         if(j >= h[i-1])
    //             pick = s[i-1] + dp[i-1][j - h[i-1]];
    //         dp[i][j] = max(pick, notpick);
    //     }
    // }
    // cout<<dp[n][x];

    // o(w) space complexity
    vector<int> dp(x+1, 0);
    for(int i = 0; i < n; i++)
        for(int j = x; j >= h[i]; j--)
            dp[j] = max(dp[j], dp[j - h[i]] + s[i]);
    
    cout<<dp[x];
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