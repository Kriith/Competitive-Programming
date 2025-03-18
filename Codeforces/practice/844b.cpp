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

ll binpow(ll a, ll b){
    if (b == 0)
        return 1;
    ll res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

void solve(){
    int n, m;
    cin>>n>>m;
    int a[n][m];
    lop(i, n) lop(j, m) cin>>a[i][j];

    ull ans = 0;
    int c0 = 0, c1 = 0;
    lop(i, n){
        c0 = c1 = 0;
        lop(j, m){
            if(a[i][j] == 0) c0++;
            else c1++;
        }
        ans += binpow(2, c0) + binpow(2, c1) - 2;
        dbg(i, c0, c1, ans);
    }
    lop(i, m){
        c0 = c1 = 0;
        lop(j, n){
            if(a[j][i] == 0) c0++;
            else c1++;
            // dbg(i, j, a[i][j], c0, c1);
        }
        ans += binpow(2, c0) + binpow(2, c1) - 2;
        dbg(i, c0, c1, ans);
    }
    ans -= m*n;
    cout<<ans<<nl;
    // lop(i, m) lop(j, n) cout<<a[i][j]<<sp;
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