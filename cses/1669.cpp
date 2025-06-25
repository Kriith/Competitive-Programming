#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sp " "

bool dfs(int u, int p, vector<vector<int>>& adj, vector<bool>& marked, vector<int>& ans, bool& flg){
    marked[u] = 1;
    for(auto i: adj[u]){
        // cout<<i<<sp<<u<<sp<<p<<sp<<marked[i]<<endl;
        if(i == p) continue;
        if(marked[i] && p > 0){ ans.push_back(i); return true; }
        else if(dfs(i, u, adj, marked, ans, flg)){
            if(flg) return true; 
            ans.push_back(i); 
            if(ans[0] == u){ ans.push_back(u); flg = 1; }
            else if(i == ans[0]) flg = 1;
            return true; 
        }
    }
    return false;
}

void solve(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    while(m--){
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> marked(n+1, 0);
    vector<int> ans;
    bool flg =  0;
    for(int i = 1; i < n; i++){
        // cout<<i<<endl;
        if(marked[i]) continue;
        if(dfs(i, 0, adj, marked, ans, flg)){
            // cout<<i<<endl;
            // ans.push_back(i);
            break;
        }
    }

    if(ans.empty() || ans.size() < 4) cout<<"IMPOSSIBLE";
    else{
        cout<<ans.size()<<endl;
        for(auto i: ans) cout<<i<<sp;
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
    // cin>>t; 
    while(t--)
        solve();
    return 0;
}