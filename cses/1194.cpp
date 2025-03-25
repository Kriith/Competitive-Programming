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

int df[] = {0, -1, 0, 1, 0};
pi bfs(queue<pi>& q, vvi& dist, bool flg, vvc& c, vvi& dir){
    int d = 1, n = c.size(), m = c[0].size();
    vvb marked(n, vb(m, 0));
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            lop(i, 4){
                int x = q.front().ff + df[i], y = q.front().ss + df[i+1];
                if(x < 0 || x >= n || y < 0 || y >= m || c[x][y] == '#' || marked[x][y]) continue;
                marked[x][y] = 1;
                if(flg && d < dist[x][y] && c[x][y] == '.'){
                    dir[x][y] = i;
                    dbg(x, y, flg, d, dist[x][y], dir[x][y]);
                    if(x == 0 || x == n-1 || y == 0 || y == m-1) return make_pair(x, y);
                }
                else dist[x][y] = d;
                q.push({x, y});
            }
            q.pop();
        }
        d++;
    }
    return {-1, -1};
}

void solve(){
    int n, m;
    cin>>n>>m;
    vvc c(n, vc(m));
    lop(i, n) lop(j, m) cin>>c[i][j];

    //monster bfs
    queue<pi> q;
    vvi mdist(n, vi(m, INT_MAX));
    int ax = -1, ay = -1;
    lop(i, n){
        lop(j, m){
            if(c[i][j] == 'M')
                q.push({i, j});
            else if(c[i][j] == 'A')
                ax = i, ay = j;
        }
    }
    if(ax == 0 || ay == 0 || ax == n-1 || ay == m-1){ cout<<"YES\n0"; return; }
    vvi dir(n, vi(m, -1));
    if(!q.empty()) bfs(q, mdist, 0, c, dir);
    // q.clear();
    while(!q.empty()) q.pop();
    q.push({ax, ay});
    pi st = bfs(q, mdist, 1, c, dir);
    if(st.ff < 0){ cout<<"NO"; return; }
    string ans = "";
    char step[] = {'L', 'U', 'R', 'D'};
    while(st.ff != ax || st.ss != ay){
        int t = dir[st.ff][st.ss];
        ans.pb(step[t]);
        st.ff -= df[t], st.ss -= df[t+1];
    }
    reverse(all(ans));
    cout<<"YES\n"<<ans.size()<<nl<<ans;
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