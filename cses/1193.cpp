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
    int n, m;
    cin>>n>>m;
    vector<vector<char>> c(n, vector<char>(m));
    lop(i, n) lop(j, m) cin>>c[i][j];

    int ax = -1, ay = -1, bx = -1, by = -1;
    lop(i, n){
        lop(j, m){
            if(c[i][j] == 'A'){
                ax = i, ay = j;
                if(bx >= 0) break;
            }
            else if(c[i][j] == 'B'){
                bx = i, by = j;
                if(ax >= 0) break;
            }
        }
    }
    int df[] = {0, -1, 0, 1, 0};
    vector<vector<bool>> marked(n, vector<bool>(m, 0));
    queue<pi> q;
    q.push({ax, ay});
    marked[ax][ay] = 1;
    vvi dir(n, vi(m, -1));
    // bool flg = 0;
    while(!q.empty()){
        lop(i, 4){
            int x = q.front().ff + df[i], y = q.front().ss + df[i+1];
            if(x < 0 || x >= n || y < 0 || y >= m || c[x][y] == '#' || c[x][y] == 'A' || marked[x][y])
            continue;
            marked[x][y] = 1;
            dir[x][y] = i;
            if(c[x][y] == '.') q.push({x, y});
            else break;
        }
        if(marked[bx][by]) break;
        q.pop();
    }
    // dbg(dir);
    if(!marked[bx][by]){ cout<<"NO\n"; return; }
    int i = bx, j = by;
    char step[] = {'L', 'U', 'R', 'D'};
    string ans = "";
    while(c[i][j] != 'A'){
        // dbg(i, j, ans, dir[i][j], df[dir[i][j]], df[dir[i][j] + 1]);
        int t = dir[i][j];
        ans.push_back(step[t]);
        i -= df[t]; j -= df[t + 1];
        // dbg(i, j, ans);
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
// dfs approach tle
// string ans = "";

// void dfs(int x, int y, string curr, vector<vector<char>>& c, int d, vvi& dist){
//     dbg(ans, x, y, d, curr);
//     int n = c.size(), m = c[0].size();
//     int df[] = {0, -1, 0, 1, 0};
//     char step[] = {'L', 'U', 'R', 'D'};
//     lop(i, 4){
//         int nx = x + df[i], ny = y + df[i+1];
//         if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
//         if(c[nx][ny] == 'B'){
//             if(d+1 < dist[nx][ny]){ 
//                 ans = curr + step[i];
//                 dist[nx][ny] = d + 1;
//             }
//             return;
//         }
//         else if(c[nx][ny] != '.' || dist[nx][ny] < d + 1) continue;
//         dist[nx][ny] = d + 1;
//         dfs(nx, ny, curr + step[i], c, d+1, dist);
//     }
// }

// void solve(){
//     int n, m;
//     cin>>n>>m;
//     vector<vector<char>> c(n, vector<char>(m));
//     lop(i, n) lop(j, m) cin>>c[i][j];

//     int x, y, bx, by;
//     lop(i, n){
//         lop(j, m){
//             if(c[i][j] == 'A')
//                 x = i, y = j;
//             else if(c[i][j] == 'B')
//                 bx = i, by = j;
//         }
//     }
//     dbg(x, y, bx, by);
//     vvi dist(n, vi(m, 2005));
//     dfs(x, y, "", c, 0, dist);
//     if(ans == ""){ cout<<"NO"; return; }
//     cout<<"YES\n"<<dist[bx][by]<<nl<<ans;
// }
