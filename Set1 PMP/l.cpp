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
    ll n, m;
    cin>>n>>m;
    vll a(m);
    lop(i, m) cin>>a[i];
    priority_queue<ll> mx(all(a));
    priority_queue<ll, vll, greater<ll>> mn(all(a));
    ll mxa = 0, mna = 0;
    lop(i, n){
        mxa += mx.top();
        mna += mn.top();
        ll x = mx.top() - 1;
        ll y = mn.top() - 1;
        mx.pop(); mn.pop();
        if(x > 0) mx.push(x);
        if(y > 0) mn.push(y);
        dbg(i, mn.top(), mx.top());
    }
    cout<<mxa<<sp<<mna<<nl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("C:/Users/HP/Desktop/Competitive Programming/input.txt", "r", stdin);
    freopen("C:/Users/HP/Desktop/Competitive Programming/output.txt", "w", stdout);
#endif
    // int t;
    // cin>>t;
    // while(t--)
        solve();
    return 0;
}