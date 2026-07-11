#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sp " "

void solve(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj(n + 1);
    vector<int> inDegree(n + 1, 0), dp(n + 1, 0);
    
    for(int i = 0; i < m; i++) {
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        inDegree[y]++;
    }

    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(!inDegree[i]) q.push(i);
    }

    while(!q.empty()) {
        int t = q.front();
        q.pop();
        for(int i: adj[t]) {
            if(dp[i] < dp[t] + 1) {
                dp[i] = dp[t] + 1;
            }
            if(--inDegree[i] == 0) {
                q.push(i);
            }
        }
    }
    cout<<*max_element(dp.begin(), dp.end());
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