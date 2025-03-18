#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using mint = map<int, int>;
using mll = map<ll, ll>;
using pi = pair<int, int>;

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

#ifndef ONLINE_JUDGE
#include "C:/Users/HP/Desktop/Competitive Programming/debug.h"
#else
#define dbg(...) 42
#endif

void solve(){
    ll n, c;
    cin>>n>>c;
    vll a(n), ans(n);
    lop(i, n) cin>>a[i];
    a[0] += c;
    ll mx = 0;
    lop(i, n) mx = (a[mx] >= a[i])?mx:i;
    // dbg(mx);
    vll pf(n+1, 0);
    lop(i, n) pf[i+1] = pf[i] + a[i];
    // dbg(pf);
    lop(i, n){
        if(i < mx) ans[i] = (pf[i+1] >= a[mx])?i:(i+1);
        else if(i == mx) ans[i] = 0;
        else ans[i] = i;
    }
    lop(i, n) cout<<ans[i]<<sp;
    cout<<nl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("C:/Users/HP/Desktop/Competitive Programming/input.txt", "r", stdin);
    freopen("C:/Users/HP/Desktop/Competitive Programming/output.txt", "w", stdout);
#endif
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}