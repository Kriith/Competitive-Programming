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
    ll w, h, n;
    cin>>w>>h>>n;
    set<ll> l, b;
    multiset<ll> L, B;
    l.insert(0), l.insert(w), b.insert(0), b.insert(h), L.insert(w), B.insert(h);
    auto push = [&](ll x, set<ll> &y, multiset<ll> &z){
        // cout<<"in";
        y.insert(x); auto i = y.find(x);
        ll j = *(++i) - x; i--; 
        ll k = x - *(--i);
        dbg(z);
        z.erase(z.find(j + k));
        z.insert(j), z.insert(k);
        dbg(j, k, z);
    };
    while(n--){
        char c; ll a;
        cin>>c>>a;
        if(c == 'H') push(a, b, B);
        else push(a, l, L);
        // cout<<'i';
        cout<<(*(L.rbegin()) * (*(B.rbegin())))<<nl;
    }
    return;
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