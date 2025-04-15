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
    int n, m, H;
    cin>>n>>m>>H;
    vb h(n+1, 0);
    vvi adj(n+1);
    lop(i, H){
        int x; cin>>x;
        h[x] = 1;
    }
    lop(i, n){
        int u, v, w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    //flag method, insert flag into djikstra set
    vvll dist(n+1, vll(2, LONG_LONG_MAX));  //2d array, when on horse and not on horse
    int prevh = 0, currh = 0;
    set<ll> s;
    s.insert({0, 1, 0});
    while(!s.empty()){
        auto i = s.begin();
        s.erase(s.begin());
        currh = prevh || ((*i)[2] == 1);
        
        for(auto j : adj[(*i)[0]]){
            if(dist[][currh] > dist[][prevh] + )
        }
    }

    //parallel graph method, make parallel graph whose nodes are connected at h[i] with 0 weight

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