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
    int n, m;
    cin>>n>>m;
    vector<pair<int, int>> a(n);
    lop(i, n) cin>>a[i].ff;
    lop(i, n) cin>>a[i].ss;
    sort(all(a));

    ll ans = 0;
    lop(i, n) ans += 2LL*(a[i].ss - 2)*(a[i].ss - 1) + 4LL*a[i].ss;
    lop(i, n - 1){
        int d = a[i].ff + a[i].ss + a[i + 1].ss - a[i + 1].ff;
        if(d < 0) continue;
        int r = d/2 + 1;
        if(d & 1) ans -= 2LL*r*(r - 1);
        else ans -= 2LL*(r - 2)*(r - 1) + 4LL*r;
    }
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