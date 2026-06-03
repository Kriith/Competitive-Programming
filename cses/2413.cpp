#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sp " "

int MOD =  1e9+7;

//dp[i][0] = represents rows have 2 columns, dp[i][1] = rows have 1 column
ll dp[1000001][2];

void solve(){
    int n;
    cin>>n;
    if(dp[n-1][0] == 0 && dp[n-1][1] == 0) {
        dp[0][0] = dp[0][1] = 1;
        for(int i = 1; i < n; i++) {
            if(dp[i][0] == 0 && dp[i][1] == 0) {
                dp[i][0] = ((dp[i-1][0] * 4LL)%MOD + dp[i-1][1])%MOD;
                dp[i][1] = (dp[i-1][0] + (dp[i-1][1] * 2LL)%MOD)%MOD;
            }
        }
    }
    cout<<((dp[n - 1][0] + dp[n - 1][1])%MOD)<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("C:/Users/HP/Desktop/Competitive Programming/input.txt", "r", stdin);
    freopen("C:/Users/HP/Desktop/Competitive Programming/output.txt", "w", stdout);
    #endif
    dp[0][0] = dp[0][1] = 1;
    ll t = 1;
    cin>>t; 
    while(t--)
        solve();
    return 0;
}