#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using mint = map<int, int>;
using mll = map<ll, ll>;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

#define loop(i, a, b) for(int i = a; i<b; i++)
#define pool(i, a, b) for(int i = a; i>b; i--)
#define lop(i, n) for(int i = 0; i<n; i++)
#define lopp(i, n) for(int i = 1; i<n; i++)
#define eb emplace_back
#define ef emplace_front
#define pb push_back
#define puf push_front
#define popb pop_back
#define popf pop_front
#define ff first
#define ss second
#define nl "\n"
#define sp " "
#define mie *min_element
#define mxe *max_element
#define all(x) x.begin(), x.end()

#ifndef ONLINE_JUDGE
#include "C:/Users/HP/Desktop/Competitive Programming/debug.h"
#else
#define dbg(...) 42
#endif

const int mod = 1e9+7;

void solve(){
    int n;
    cin>>n;
    char c[n][n];
    lop(i, n) lop(j, n) cin>>c[i][j];

    if(c[0][0] == '*'){ cout<<0; return; }
    vvi dp(n, vi(n));
    dp[0][0] = 1;
    lopp(i, n){
        if(c[i][0] == '*') dp[i][0] = 0;
        else dp[i][0] = dp[i-1][0];

        if(c[0][i] == '*') dp[0][i] = 0;
        else dp[0][i] = dp[0][i-1];
    }
    lopp(i, n){
        lopp(j, n){
            if(c[i][j] == '*'){ dp[i][j] = 0; continue; }
            dp[i][j] = (dp[i-1][j] + dp[i][j-1])%mod;
        }
    }
    dbg(dp);
    cout<<dp[n - 1][n - 1]%mod;
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