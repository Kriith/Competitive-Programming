#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sp " "

void solve(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < m; i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> ans;
    vector<bool> marked(n+1, 0);
    function<int(int)> dfs = [&](int t)->int{
        marked[t] = 1;
        for(auto it: adj[t]){
            if(!marked[it]) dfs()
        }
    };

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