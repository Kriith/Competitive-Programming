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
    int n, m;
    cin>>n>>m;
    vvi adj(n+1);
    vi deg(n+1, 0), curr;
    vb marked(n+1, 0);
    lop(i, m){
        int x, y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
        deg[x]++, deg[y]++;
    }
    dbg(adj, deg);

    function<void(int)> dfs = [&](int t)->void{
        // dbg(t);
        marked[t] = 1;
        curr.pb(t);
        for(auto it: adj[t]){
            if(!marked[it]) dfs(it);
        }
    };
    
    int ans = 0;
    lopp(i, n+1){
        if(!marked[i]){
            curr.pb(i);
            dfs(i);
            bool flg = 1;
            for(auto j: curr) if(deg[j] != 2) flg = 0;
            if(flg) ans++;
            curr.clear();
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
    // cin>>t; 
    while(t--)
        solve();
    return 0;
}