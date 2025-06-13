#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sp " "

void solve(){
    int n;
    cin>>n;
    vector<ll> a(n+1);
    for(int i = 1; i <= n; i++) cin>>a[i];
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < n-1; i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    queue<vector<int>> q;
    q.push({1, 0, 0});
    vector<ll> ans(n+1);
    ans[0] = 0;
    while(!q.empty()){
        vector<int> v = q.front();
        q.pop();
        ans[v[0]] = max(a[v[0]], a[v[0]] - a[v[1]] + ans[v[2]]);
        // cout<<v[0]<<sp<<ans[v[0]]<<sp<<v[1]<<sp<<ans[v[1]]<<sp<<v[2]<<sp<<ans[v[2]]<<endl;
        for(auto it: adj[v[0]]){
            if(it != v[1]) q.push({it, v[0], v[1]});
        }
    }
    for(int i = 1; i <= n; i++) cout<<ans[i]<<sp;
    cout<<endl;
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