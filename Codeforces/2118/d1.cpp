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
    int n, k;
    cin>>n>>k;
    vll p(n);
    lop(i, n) cin>>p[i];
    vi d(n);
    lop(i, n) cin>>d[i];
    // sort(all(p));
    int q;
    cin>>q;
    while(q--){
        ll a; cin>>a;
        ll t = 0;
        int nx = lower_bound(all(p), a) - p.begin();
        vvb vis(n+1, vb(2*k+1, 0));
        bool dir = 1, flg = 1;
        while(nx < n && nx >= 0){
            t += abs(p[nx] - a);
            int tt = t%k;
            if(dir){
                if(vis[nx][tt]){ cout<<"NO"<<nl; flg = 0; break; }
                else vis[nx][tt] = 1;
            }
            else{
                if(vis[nx][tt + k]){ cout<<"NO"<<nl; flg = 0; break; }
                else vis[nx][tt + k] = 1;
            }
            if(tt == d[nx]) dir = !dir;
            a = p[nx];
            if(dir) nx++;
            else nx--;
        }
        if(flg) cout<<"YES"<<nl;
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