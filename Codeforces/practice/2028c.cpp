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
    int n, m, v;
    cin>>n>>m>>v;
    vi a(n);
    lop(i, n) cin>>a[i];

    vll pf(n+1);
    pf[0] = 0;
    lop(i, n) pf[i+1] = pf[i] + a[i];
    ll sum = pf[n-1], cursum = 0;
    int t = -1;
    lop(i, n){
        dbg(i, pf[i], cursum, t, sum);
        if(pf[i] - cursum >= v && m > 0){
            int j = t + 1;
            while(pf[i] - pf[j] - cursum > v && j < i) j++;
            if (j < i){
                cursum += pf[i] - pf[j];
                sum -= pf[i] - pf[j];
                t = i; m--;
            }
        }
    }
    if(m > 0 || sum < 0) cout<<-1<<nl;
    else cout<<sum<<nl;
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