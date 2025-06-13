#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vc = vector<char>;
using vvc = vector<vector<char>>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
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
    int n; cin>>n;
    vi a(n), b(n);
    lop(i, n) cin>>a[i];
    lop(i, n) cin>>b[i];

    int ans = 0;
    map<int, int> mp;
    lop(i, n) mp[a[i]] = i;
    lop(i, n){
        if(mp.find(b[i]) != mp.end()){
            if((mp[b[i]] & 1) == (i & 1)) ans = max(ans, 1+min(mp[b[i]], i));
            else if(abs(i - mp[b[i]]) != 1) ans = max(ans, 1 + min(mp[b[i]], i));
        }
    }
    mp.clear();
    map<int, int> mp2;
    lop(i, n){
        if(mp.find(a[i]) == mp.end()) mp[a[i]] = i;
        else{
            ans = max(ans, 1 + min(mp[a[i]], i));
            mp[a[i]] = i;
        }
        if(mp2.find(b[i]) == mp2.end()) mp2[b[i]] = i;
        else{
            ans = max(ans, 1 + min(mp2[b[i]], i));
            mp2[b[i]] = i;
        }
    }
    cout<<ans<<nl;
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