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

void solve(){
    int n;
    cin>>n;
    vll a(n);
    lop(i, n) cin>>a[i];
    vll pf(n, 0), sf(n, 0);
    pf[0] = max(0LL, a[0]), sf[n - 1] = min(0LL, a[n - 1]);
    lopp(i, n) pf[i] = pf[i - 1] + max(0LL, a[i]);
    pool(i, n - 2, -1) sf[i] = sf[i + 1] + min(0LL, a[i]);
    ll ans = 0;
    lop(i, n) ans = max(ans, pf[i] + -1LL*sf[i]);
    cout<<ans<<nl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("C:/Users/HP/Desktop/Competitive Programming/input.txt", "r", stdin);
    freopen("C:/Users/HP/Desktop/Competitive Programming/output.txt", "w", stdout);
#endif
    ll t = 1;
    cin>>t; 
    while(t--)
        solve();
    return 0;
}

//MLE && TLE Soln
// void solve(){
//     int n;
//     cin>>n;
//     vi a(n);
//     lop(i, n) cin>>a[i];
//     vvll dp(n, vll(n, 0LL));

//     function<ll(int, int)> rec = [&](int l, int r)->ll{
//         if(l > r || dp[l][r] > 0) return dp[l][r];
//         if(l == r){ 
//             dp[l][r] = abs(a[l]);
//             return dp[l][r];
//         }
//         int li = l, ri = r;
//         while(a[li] > 0 && li <= r) dp[l][r] += 1LL*a[li++];
//         while(a[ri] < 0 && ri >= l) dp[l][r] += -1LL*a[ri--];
//         ll t = 0;
//         loop(i, li, ri + 1){
//             if(a[i] > 0) t = max(t,1LL*a[i] + ((i < ri)?rec(i + 1, ri):0LL));
//             else t = max(t,-1LL*a[i] + ((i > li)?rec(li, i - 1):0LL));
//         }
//         dp[l][r] += t;
//         dbg(l, r, dp[l][r]);
//         return dp[l][r];
//     };
//     cout<<rec(0, n-1)<<nl;
// }