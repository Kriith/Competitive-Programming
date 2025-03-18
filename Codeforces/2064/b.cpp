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
    mint mp;
    lop(i, n) mp[a[i]]++;
    vector<bool> single(n, 0);
    lop(i, n) if(mp[a[i]] == 1) single[i] = 1;
    int l = -1, r = -1, cnt = 0, curl = -1, curr = -1, mx = 0;
    lop(i, n){
        if(single[i]){
            cnt++;
            if(cnt == 1) curl = i;
            curr = i;
            if(cnt > mx){ l = curl, r = curr, mx = cnt; }
        }
        else{ 
            if(cnt > mx){ l = curl, r = curr, mx = cnt; }
            cnt = 0, curl = curr = -1;
        }
    }
    if(mx == 0) cout<<0<<nl;
    else cout<<(l+1)<<sp<<(r+1)<<nl;
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