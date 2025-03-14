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
    ll n;
    cin>>n;
    vll a(n);
    lop(i, n) cin>>a[i];
    vll fwd(n), bwd(n);
    fwd[0] = bwd[n-1] = 0;
    fwd[1] = bwd[n-2] = 1;
    lopp(i, n-1){
        if((a[i+1] - a[i]) < (a[i] - a[i-1])) fwd[i+1] = fwd[i] + 1;
        else fwd[i+1] = fwd[i] + a[i+1] - a[i];
    }
    pool(i, n-2, 0){
        if((a[i] - a[i-1]) < (a[i+1] - a[i])) bwd[i-1] = bwd[i] + 1;
        else bwd[i-1] = bwd[i] + a[i] - a[i-1];
    }
    ll m;
    cin>>m;
    lop(i, m){
        ll x, y;
        cin>>x>>y;
        x--;
        y--;
        if(x < y) cout<<(fwd[y] - fwd[x])<<nl;
        else cout<<(bwd[y] - bwd[x])<<nl;
    }
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