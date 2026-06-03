#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sp " "

void solve(){
    int n; cin>>n;
    vector<ll> x(n), y(n), c(n), k(n);
    for(int i = 0; i < n; i++) cin>>x[i]>>y[i];
    for(int i = 0; i < n; i++) cin>>c[i];
    for(int i = 0; i < n; i++) cin>>k[i];

    set<vector<ll>> s;
    vector<vector<ll>> type(n, vector<ll>(2));
    for(int i = 0; i < n; i++){
        type[i] = {c[i], -1};
        s.insert({c[i], i});
    }
    while(!s.empty()){
        vector<ll> t = *s.begin();
        s.erase(s.begin());
        for(int i = 0; i < n; i++){
            if(i == t[1]) continue;
            ll cost = (k[t[1]] + k[i])*(abs(x[t[1]] - x[i]) + abs(y[t[1]] - y[i]));
            if(cost < type[i][0]){
                type[i] = {cost, t[1]};
                // s.insert({cost, i});
            }
        }
    }
    ll cost = 0;
    vector<int> stations;
    set<pair<int, int>> connections;
    for(int i = 0; i < n; i++){
        cost += type[i][0];
        if(type[i][1] < 0) stations.push_back(i+1);
        else connections.insert({min(i, (int)type[i][1]) + 1, max(i, (int)type[i][1]) + 1});
    }
    cout<<cost<<endl<<stations.size()<<endl;
    for(auto i: stations) cout<<i<<sp;
    if(stations.size()) cout<<endl;
    map<pair<int, int>, int> mp;
    for(int i = 0; i < n; i++){
        if(mp.find({x[i], y[i]}) != mp.end()){
            connections.insert({mp[{x[i], y[i]}] + 1, i + 1});
        }
        else mp[{x[i], y[i]}] = i;
    }
    cout<<connections.size()<<endl;
    for(auto i: connections) cout<<i.first<<sp<<i.second<<endl;
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