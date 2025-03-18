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
    vi a(n), b(m);
    lop(i, n) cin>>a[i];
    lop(i, m) cin>>b[i];
    // sort(all(a)); sort(all(b));
    
    priority_queue<int> c(all(a)), d(all(b));
    // cout<<c.top()<<sp<<d.top()<<nl;
    // dbg(c.top(), d.top(), d.size(), c.size());
    while(!d.empty() && !c.empty() && d.size() <= c.size() && d.top() >= c.top()){
        // dbg(c.top(), d.top(), d.size(), c.size());
        if(c.top() == d.top()){ c.pop(); d.pop(); }
        else{ int x = d.top(); d.pop(); d.push(x/2); d.push((x+1)/2); }
    }
    if(c.empty() && d.empty()) cout<<"YES\n";
    else cout<<"NO\n";
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