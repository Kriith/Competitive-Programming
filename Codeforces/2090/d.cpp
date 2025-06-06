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

vector<bool> prime(1e5+1, 1);

void getprimes(){
    loop(i, 2, 1e5+1){
        if(prime[i]){
            for(int j = 2*i; j < 1e5 + 1; j += i) prime[j] = 0;
        }
    }
    prime[1] = prime[0] = 0;
}

void solve(){
    int n; 
    cin>>n;
    int l = max(n/3, 1), r = ceil(2.0*n/3.0) + 1, p = -1;
    loop(i, l, r){
        if(prime[i]){ p = i; break; }
    }
    dbg(l, r, p);
    cout<<p<<sp;
    lopp(i, max(n - p + 1, p)){
        if(p - i > 0) cout<<(p-i)<<sp;
        if(p + i <= n) cout<<(p+i)<<sp;
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
    getprimes();
    while(t--)
        solve();
    return 0;
}