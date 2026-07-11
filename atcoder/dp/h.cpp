#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sp " "

const int MOD = 1e9 + 7;

void solve(){
    int h, w;
    cin>>h>>w;
    vector<vector<char>> a(h, vector<char>(w));

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin>>a[i][j];
        }
    }

    vector<int> dp(w + 1, 0);
    dp[1] = 1;
    for(int i = 1; i <= h; i++) {
        for(int j = 1; j <= w; j++) {
            if(a[i - 1][j - 1] == '#') {
                dp[j] = 0;
            }
            else {
                //the initial value of dp[j] is the value in the prev row at jth index
                //this removes the need of keeping a separate prev
                dp[j] = (dp[j] + dp[j - 1]) % MOD;
            }
        }
    }
    cout<<dp[w];
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