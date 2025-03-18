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
    int n, m, q;
    cin>>n>>m>>q;
    int a[m], b[q];
    lop(i, m) cin>>a[i];
    lop(i, q) cin>>b[i];
    sort(a, a+m);
    // dbg(b);
    ll ans = 0;
    lop(i, q){
        if(b[i] < a[0])
            ans = a[0] - 1;
        else if(b[i] > a[m-1])
            ans = n - a[m-1];
        else if(b[i] == a[0] || b[i] == a[m-1])
            ans = 0;
        else{
            int r = upper_bound(a, a + m, b[i]) - a;
            int l = lower_bound(a, a + m, b[i]) - a - 1;
            dbg(l, r);
            ans = (a[r]-a[l])/2;
        }
        cout<<ans<<nl;
        ans = 0;
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