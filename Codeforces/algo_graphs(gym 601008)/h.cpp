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
    int n;
    cin>>n;
    vi a(n);
    lop(i, n) cin>>a[i];

    //find vertices which are in a cycle
    vb marked(n+1, 0);
    vi ind(n+1, 0);
    lop(i, n) ind[a[i]]++;
    // dbg(ind);
    queue<int> q;
    lopp(i, n + 1) if(ind[i] == 0) q.push(i);
    int vis = 0;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        marked[t] = 1;
        vis++;
        ind[a[t-1]]--;
        if(ind[a[t-1]] == 0) q.push(a[t-1]);
    }
    // dbg(vis);
    if(vis == 0){ cout<<2<<nl; return; }
    dbg(marked);

    //marked[i] = 0 then it is in cycle
    //dfs to find longest path from any acyclic vertex to cyclic vertex
    int mxlen = 0;
    vb visited(n+1, 0);
    vi paths(n+1, 0);
    function<int(int, int)> dfs = [&](int t, int len)->int{
        // dbg(t);
        if(!marked[t]){ mxlen = max(mxlen, len); return len; }
        visited[t] = 1;
        // curr.pb(t);
        if(!visited[a[t-1]])  return dfs(a[t-1], len+1);
        else{
            mxlen = max(mxlen, len + paths[a[t-1]]);
            return len + paths[a[t-1]];
        }
    };
    lopp(i, n+1) if(marked[i]) paths[i] = dfs(i, 1);
    dbg(paths);
    cout<<(mxlen + 1)<<nl;
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