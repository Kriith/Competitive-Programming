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
    sort(all(a));

    int repeating = -1, ri = -1;
    lop(i, n - 1){
        if(a[i] == a[i+1]){ repeating = a[i]; ri = i; }
    }
    if(repeating < 0){ cout<<-1<<nl; return; }
    a.erase(a.begin() + ri); a.erase(a.begin() + ri);
    dbg(a);
    int diff = INT_MAX, di = -1;
    lop(i, n - 3){ 
        if(diff >= a[i+1] - a[i]){
            diff = a[i+1] - a[i];
            di = i;
        }
    }
    if(diff >= 2*repeating) cout<<-1<<nl;
    else cout<<repeating<<sp<<repeating<<sp<<a[di]<<sp<<a[di+1]<<nl;
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