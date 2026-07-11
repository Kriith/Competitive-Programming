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
    vll c(n), d(n);
    lop(i, n) cin>>c[i];
    lop(i, n) cin>>d[i];
    lop(i, n){
        while(!(c[i]&1)) c[i] /= 2;
        while(!(d[i]&1)) d[i] /= 2;
    }
    multiset<ll> a(all(c)), b(all(d));
    lop(i, n){
        ll x = *(b.begin());
        while(!(a.contains(x)) && (x > 1)) x /= 2;
        if(a.contains(x)){ a.erase(a.find(x)); b.erase(b.begin()); }
        else break;
    }
    if(a.empty() && b.empty()) cout<<"YES\n";
    else cout<<"NO\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("C:/Users/HP/Desktop/Competitive Programming/input.txt", "r", stdin);
    freopen("C:/Users/HP/Desktop/Competitive Programming/output.txt", "w", stdout);
#endif
    ll t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}