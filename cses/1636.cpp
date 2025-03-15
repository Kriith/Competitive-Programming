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
    int n, x;
    cin>>n>>x;
    vi c(n);
    lop(i, n) cin>>c[i];
    sort(all(c));

    vvi dp(n, vi(x+1, 0));
    // lop(i, n) dp[0][i] = 1;
    int t = 0;
    while(t * c[0] <= x){ dp[0][t*c[0]] = 1; t++; }
    lopp(i, n){
        // if(i%c[0] == 0) dp[i][0] = 1;
        dp[i][0] = 1;
        lopp(j, x+1){
            // dp[i][j] = dp[i][j-1]%mod;
            // if(i >= c[j]) dp[i][j] = (dp[i][j] +  dp[i - c[j]][j])%mod;
            dp[i][j] = dp[i-1][j]%mod;
            if(j >= c[i]) dp[i][j] = (dp[i][j] + dp[i][j - c[i]])%mod;
        }
    }
    dbg(dp);
    cout<<dp[n-1][x]%mod;
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