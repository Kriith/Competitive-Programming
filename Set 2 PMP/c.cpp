#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using mint = map<int, int>;
using mll = map<ll, ll>;
using pi = pair<int, int>;

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

#ifndef ONLINE_JUDGE
#include "C:/Users/HP/Desktop/Competitive Programming/debug.h"
#else
#define dbg(...) 42
#endif

void solve(){
    ll n, m;
    cin>>n>>m;
    ll o = n, t = 2;
    int n2 = 0, n5 = 0;
    while(o%t == 0){ n2++; t*= 2; }
    o = n, t = 5;
    while(o%t == 0){ n5++; t*= 5; }
    ll k = 1;
    if(n2 < n5){
        while(k*2 <= m && (n2 < n5)){k*= 2; n2++;}
    }
    // dbg(k);
    else if(n2 > n5){
        while(k*5 <= m && (n2 > n5)){k*= 5; n5++;}
    }
    if(n2 == n5){
        while(k*10 <= m) k*=10;
    }
    // dbg(k);
    k = (m/k)*k;
    // dbg(k);
    cout<<(n*k)<<nl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("C:/Users/HP/Desktop/Competitive Programming/input.txt", "r", stdin);
    freopen("C:/Users/HP/Desktop/Competitive Programming/output.txt", "w", stdout);
#endif
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}