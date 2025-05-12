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
    int n, m, h;
    cin>>n>>m>>h;
    vll horses(n+1, 0);
    lop(i, h){
        int x; cin>>x;
        horses[x] = 1;
    }
    vector<vvll> adj(2*n+1);
    lop(i, m){
        int u, v, w;
        cin>>u>>v>>w;
        // dbg(u, v, w, n+u, n+w);
        adj[u].pb({v, w});
        adj[v].pb({u, w});
        adj[n+u].pb({n+v, w/2});
        adj[n+v].pb({n+u, w/2});
    }
    lopp(i, n+1){
        if(horses[i] > 0)
            adj[i].pb({n+i, 0});
    }
    // dbg(adj);
    vll dist1(2*n+1, LONG_LONG_MAX), dist2(2*n+1, LONG_LONG_MAX);
    set<vll> s;
    s.insert({0, 1});
    dist1[1] = 0, dist2[n] = 0;
    while(!s.empty()){
        vll t = *s.begin();
        s.erase(s.begin());
        if(t[0] > dist1[t[1]]) continue;
        for(auto it : adj[t[1]]){
            if(t[0] + it[1] < dist1[it[0]]){
                dist1[it[0]] = t[0] + it[1];
                s.insert({t[0] + it[1], it[0]});
            }
        }
    }
    // dbg(dist1);
    s.clear();
    s.insert({0, n});
    while(!s.empty()){
        vll t = *s.begin();
        s.erase(s.begin());
        if(t[0] > dist2[t[1]]) continue;
        for(auto it : adj[t[1]]){
            if(t[0] + it[1] < dist2[it[0]]){
                dist2[it[0]] = t[0] + it[1];
                s.insert({t[0] + it[1], it[0]});
            }
        }
    }
    // dbg(dist2);
    ll ans = LONG_LONG_MAX;
    lopp(i, n+1)
    ans = min(ans, max(min(dist1[i], dist1[n+i]), min(dist2[i], dist2[n+i])));
    if(ans == LONG_LONG_MAX) cout<<-1<<nl;
    else cout<<ans<<nl;

    //second method

    /*
    vector<int> dist1(n+1, __LONG_LONG_MAX__), dist2(n+1, __LONG_LONG_MAX__);
    set<vector<int>> s;
    s.insert({0, 1, troppas[1]});
    while(!s.empty()){
        vector<int> t = *s.begin();
        s.erase(s.begin());
        for(auto it : adj[t[1]]){
            int dist = it[1];
            if(t[2] > 0) dist /= 2;
            dist += t[0];
            int halve = max(t[2], troppas[it[0]]);
            if(dist < dist1[it[0]]){
                dist1[it[0]] = dist;
                s.insert({dist, it[0], halve});
            }
        }
    }
    s.clear();
    s.insert({0, n, troppas[n]});
    while(!s.empty()){
        vector<int> t = *s.begin();
        s.erase(s.begin());
        for(auto it : adj[t[1]]){
            int dist = it[1];
            if(t[2] > 0) dist /= 2;
            dist += t[0];
            int halve = max(t[2], troppas[it[0]]);
            if(dist < dist2[it[0]]){
                dist2[it[0]] = dist;
                s.insert({dist, it[0], halve});
            }
        }
    }
    int ans = __LONG_LONG_MAX__;
    dist1[0] = dist2[n] = 0;
    for(int i = 1; i <= n; i++){
        ans = min(ans, max(dist1[i], dist2[i]));
    }
    if(ans == __LONG_LONG_MAX__) return -1;
    return ans
    */
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