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

int mex(vi &a){   
    sort(all(a));
    int mex = 0;
    lop(i, 3) if(a[i] == mex) mex++;
    return mex;
}

void solve(){
    int n, x, y;
    cin>>n>>x>>y;

    if(n == 3){ cout<<"0 1 2\n"; return; }
    vi a(n, -1);
    x--, y--;
    lop(i, n){
        vi frns;
        if(i == 0){ frns.pb(a[n-1]); frns.pb(a[1]); }
        else if(i == n - 1){ frns.pb(a[0]); frns.pb(a[n-2]); }
        else{ frns.pb(a[i-1]); frns.pb(a[i+1]); }
        if(i == x) frns.pb(a[y]);
        else if(i == y) frns.pb(a[x]);
        a[i] = mex(frns);
    }   
    lop(i, n) cout<<a[i]<<sp;
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