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

    vll pf(n);
    pf[0] = a[0];
    lop(i, n-1) pf[i+1] = pf[i] + a[i+1];
    vi dp(n, 0);
    int stopi = -1;
    if(a[0] == 0){ dp[0] = 1; stopi = 0; }
    dbg(pf);
    lopp(i, n){
        if(a[i] == 0){ dp[i] = dp[i-1] + 1; stopi = i; }
        else{
            if(pf[i] == 0 && stopi < 0){
                stopi = i;
                dp[i] = 1;
                continue;
            }
            bool flg = 1;
            pool(j, i-1, stopi){
                if(pf[j] == pf[i]){
                    dp[i] = dp[j] + 1;
                    stopi = i;
                    flg = 0;
                    break;
                }
            }
            if(flg) dp[i] = dp[i-1];
        }
    }
    cout<<dp[n-1]<<nl;
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