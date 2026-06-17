#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sp " "

void solve(){
    int n;
    cin>>n;
    vector<int> x(n), y(n), c(n), k(n);
    for(int i = 0; i < n; i++) {
        cin>>x[i]>>y[i];
    }
    for(int i = 0; i < n; i++) {
        cin>>c[i];
    }
    for(int i = 0; i < n; i++) {
        cin>>k[i];
    }

    vector<int> parent(n, -1), station;
    vector<bool> vis(n, 0);
    ll total = 0;
    for(int i = 0; i < n; i++) {
        int u = -1;
        //finding the vertex with current min value that has not been visited
        for(int j = 0; j < n; j++) {
            if(!vis[j] && (u < 0 || c[j] < c[u])) {
                u = j;
            }
        }
        vis[u] = 1;
        total += c[u];
        if(parent[u] < 0) {
            station.push_back(u);
        }
        for(int j = 0; j < n; j++) {
            if(!vis[j]) {
                ll cost = 1LL * (k[u] + k[j]) * ((abs(x[u] - x[j]) + abs(y[u] - y[j])));
                if(cost < c[j]) {
                    parent[j] = u;
                    c[j] = cost;
                }
            }
        }
    }

    cout<<total<<endl;
    cout<<station.size()<<endl;
    for(int i: station) {
        cout<<(i + 1)<<endl;
    }
    cout<<(n - station.size())<<endl;
    for(int i = 0; i < n; i++) {
        if(parent[i] >= 0) {
            cout<<(i + 1)<<sp<<(parent[i] + 1)<<endl;
        }
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