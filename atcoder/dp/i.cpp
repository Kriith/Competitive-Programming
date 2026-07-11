#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sp " "

void solve(){
    int n;
    cin>>n;
    vector<double> p(n);
    for(int i = 0; i < n; i++) {
        cin>>p[i];
    }

    vector<double> dp(n+1, 0);
    dp[0] = 1;

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j >= 0; j--) {
            if(j > 0) dp[j] = dp[j] * (1 - p[i]) + p[i] * dp[j - 1];
            else dp[j] = dp[j] * (1 - p[i]);
        }
    }

    cout<<setprecision(10)<<accumulate(dp.begin() + (n + 1)/2, dp.end(), 0.0);
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