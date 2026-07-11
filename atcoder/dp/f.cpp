#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sp " "

void solve(){
    string s, t;
    cin>>s>>t;
    int n = s.length(), m = t.length();
    vector<string> dp(m + 1, ""), prev(m + 1, "");
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(prev[j].length() > dp[j].length()) {
                dp[j] = prev[j];
            }
            if(dp[j - 1].length() > dp[j].length()) {
                dp[j] = dp[j - 1];
            }
            if(prev[j - 1].length() + (s[i - 1] == t[j - 1]) > dp[j].length()) {
                dp[j] = prev[j - 1] + s[i - 1];
            }
        }
        prev = dp;
    }
    cout<<dp[m];
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