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
    vi a(n);
    lop(i, n) cin>>a[i];

    vi amx(n), amn(n), ans(n);
    amx[0] = a[0], amn[n-1] = a[n-1], ans[n-1] = mxe(all(a));
    lopp(i, n){
        if(a[i] > amx[i-1]) amx[i] = a[i];
        else amx[i] = amx[i-1];
    }
    dbg(amx);
    pool(i, n-2, -1){
        if(a[i] < amn[i+1]) amn[i] = a[i];
        else amn[i] = amn[i+1];
    }
    dbg(amn);
    pool(i, n-2, -1){
        if(amx[i] > amn[i+1]) ans[i] = ans[i+1];
        else ans[i] = amx[i];
        dbg(amx[i], amn[i+1], ans[i]);
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
    ll t = 1;
    cin>>t; 
    while(t--)
        solve();
    return 0;
}