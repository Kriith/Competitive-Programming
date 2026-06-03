#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sp " "

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    int gcdall;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        gcdall = __gcd(gcdall, a[i]);
    }

    int cnt = 0;
    for(int i = 0; i < n; i++)
        if(a[i] == gcdall) cnt++;
    if(cnt){
        cout<<(n-cnt)<<endl;
        return;
    }

    //shortest path approach
    // vector<int> dist(5001, INT_MAX); 
    // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // for(int i = 0; i < n; i++){
    //     dist[a[i]] = 1;
    //     pq.push({1, a[i]});
    // }
    // while(!pq.empty()){
    //     auto p = pq.top();
    //     pq.pop();
    //     if(p.second == gcdall){
    //         cout<<(n + p.first - 2)<<endl;
    //         return;
    //     }
    //     for(int i = 0; i < n; i++){
    //         if(dist[__gcd(a[i], p.second)] > p.first + 1){
    //             dist[__gcd(a[i], p.second)] = p.first + 1;
    //             pq.push({p.first + 1, __gcd(a[i], p.second)});
    //         }
    //     }
    // }

    //dp approach
    int mx = *max_element(a.begin(), a.end());
    vector<int> dp(mx + 1, INT_MAX);
    for(int i = 0; i < n; i++) dp[a[i]] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= mx; j++){
            if(dp[j] < INT_MAX){
                int g = __gcd(j, a[i]);
                dp[g] = min(dp[g], dp[j] + 1);
            }
        }
    }
    cout<<(dp[gcdall] - 1 + n)<<endl;
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