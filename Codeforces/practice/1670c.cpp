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

const int m = 1e9+7;

ll binpow(ll a, ll b) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res%m;
}

void solve(){
    int n;
    cin>>n;
    vi a(n), b(n), c(n);
    lop(i, n) cin>>a[i];
    lop(i, n) cin>>b[i];
    lop(i, n) cin>>c[i];

    mint mp;
    lop(i, n) mp[a[i]] = b[i];
    map<int, bool> mb;
    lop(i, n){
        if(c[i] > 0 || a[i] == b[i]){
            mb[a[i]] = 1;
            int t = mp[a[i]];
            while(t != a[i] && mb.find(t) == mb.end()){
                mb[t] = 1;
                t = mp[t];
            }
        }
    }
    int cnt = 0;
    lop(i, n){
        if(c[i] == 0 && mb.find(a[i]) == mb.end()){
            cnt++;
            int t = mp[a[i]];
            mb[a[i]] = 1;
            while(t != a[i] && mb.find(t) == mb.end()){
                mb[t] = 1;
                t = mp[t];
            }
        }
    }
    dbg(cnt);
    cout<<binpow(2, cnt)<<nl;
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