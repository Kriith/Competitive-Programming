#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sp " "

void solve(){
    int n, m;
    cin>>n>>m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    for(int i = 0; i < m; i++) {
        cin>>b[i];
    }

    vector<vector<int>> dp(m + 1), prev(m + 1);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            // cout<<dp[j].size()<<sp<<prev[j].size()<<sp<<j<<endl;
            if(dp[j].size() < prev[j].size()) {
                dp[j] = prev[j];
            }
            if(dp[j].size() < dp[j - 1].size()) {
                dp[j] = dp[j - 1];
            }
            if(dp[j].size() < prev[j - 1].size() + (a[i - 1] == b[j - 1])) {
                dp[j] = prev[j - 1];
                dp[j].push_back(a[i - 1]);
            }
        }
        prev = dp;
    }
    
    cout<<dp[m].size()<<endl;
    for(int i: dp[m]) cout<<i<<sp;
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