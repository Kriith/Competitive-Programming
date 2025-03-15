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
    int n, m, q;
    cin>>n>>m>>q;
    vi a(n), b(m), s(q), t(q);
    lop(i, n) cin>>a[i];
    lop(i, m) cin>>b[i];
    lop(i, q) cin>>s[i]>>t[i];

    vi c(n);
    lop(i, n){ a[i]--; c[a[i]] = i; }
    lop(i, m){ b[i]--; b[i] = c[b[i]]; }
    lop(i, q){ t[i]--; t[i] = c[t[i]]; s[i]--; }

    vi first(n, m+1);
    lop(i, m) first[b[i]] = min(first[b[i]], i);
    dbg(a, b, c, first);
    vi bi;
    lop(i, n-1){
        if(first[i] > first[i+1])
            bi.pb(i);
    }

    if(bi.empty()) cout<<"YA"<<nl;
    else cout<<"TIDAK"<<nl;
    lop(i, q){
        if(first[b[s[i]]] < s[i]){
            if(first[t[i]] > s[i]){
                first[t[i]] = s[i];
                if(first[t[i]] > first[t[i] + 1] )
        }
    }   
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