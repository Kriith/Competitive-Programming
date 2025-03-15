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
    int n, k; 
    cin>>n>>k;
    vi a(n);
    lop(i, n) cin>>a[i];
    vi b(2*k, 0);
    int mod = 2*k;
    lop(i, n){
        int x = a[i]%mod;
        if(x + k >= 2*k){
            b[x]++, b[0]++, b[(x+k)%mod]--;
        }
        else b[x]++, b[x+k]--;
    }
    lopp(i, 2*k) b[i] += b[i-1];
    dbg(b);
    set<int> s;
    lop(i, 2*k){
        if(b[i] == n) s.insert(i);
    }
    if(s.empty()) cout<<-1<<nl;
    else{
        int mx = mxe(all(a));
        while(!(s.contains(mx%mod))) mx++;
        cout<<mx<<nl;
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