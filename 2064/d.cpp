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

int msb(int n){ return (31 - __builtin_clz(n)); }

void solve(){
    int n, q;
    cin>>n>>q;
    vi a(n);
    lop(i, n) cin>>a[i];
    
    vi sx(n); sx[0] = a[0]; //prefix xor
    lopp(i, n) sx[i] = sx[i - 1]^a[i];
    vvi ind(n, vi(32, -1)); //largest index with msb greater than equal to it before index j
    lop(i, n){
        lop(j, 32){
            if(msb(a[i]) >= j) ind[i][j] = i;
            else if(i > 0) ind[i][j] = ind[i - 1][j];
        }
    }
    // dbg(ind);
    
    while(q--){
        int x; cin>>x;
        int indx = n - 1;
        while(indx >= 0 && x > 0){
            int nxt = ind[indx][msb(x)];
            x ^= sx[indx]^sx[nxt];
            indx = nxt;
            if(nxt < 0 || x < a[nxt]) break;
            x ^= a[nxt];
            indx--;
        }
        cout<<(n - indx - 1)<<sp;
    }
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