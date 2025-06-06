#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, w;
    cin>>n>>w;
    vector<ll> weights(n), value(n);
    for(int i = 0; i < n; i++) cin>>weights[i]>>value[i];
    vector<ll> dp1(w+1, 0), dp2(w+1, 0);
    for(int i = 0; i < n; i++){
        dp2 = dp1;
        for(ll j = 1; j <= w; j++){
            dp1[j] = dp2[j];
            if(j >= weights[i]) dp1[j] = max(dp1[j], dp2[j - weights[i]] + value[i]);
            // cout<<dp1[j]<<" "<<dp2[j-weights[i]]<<" "<<dp2[j]<<" "<<j<<" "<<i<<endl;
        }
    }
    cout<<dp1[w];
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