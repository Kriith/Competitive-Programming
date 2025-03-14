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
    string s; cin>>s;
    ll n = stoi(s), l = s.size(), t = 0;
    if(n == 1){
        cout<<9999<<nl;
        lopp(i, 10000) cout<<i+1<<sp<<i<<nl;
        return;
    }
    vll a, b;
    while(s.size() < 7){
        ll len = s.size(), m = stoi(s) - len;
        dbg(m+len, m/(n-l));
        if(m%(n-l) == 0 && m/(n-l) <= 1e4 && m/(n-l)*l - len > 0){ 
            a.pb(m/(n-l)); 
            b.pb(m/(n-l)*l - len);
        }
        s += s[t]; t = (t >= l)?0:t+1;
    }
    int x = a.size();
    cout<<x<<nl;
    lop(i, x) cout<<a[i]<<sp<<b[i]<<nl;
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