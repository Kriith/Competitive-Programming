#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sp " "

void solve(){
    int n, w;
    cin>>n>>w;
    vector<ll> weights(n), value(n);
    for(int i = 0; i < n; i++) cin>>weights[i]>>value[i];

    ll ans = 0, valsum = accumulate(value.begin(), value.end(), 0LL);
    vector<ll> dp1(valsum+1, LLONG_MAX), dp2(valsum + 1, LLONG_MAX);
    dp1[0] = dp2[0] = 0;
    for(int i = 0; i < n; i++){
        dp2 = dp1;
        for(ll j = valsum; j >= 0; j--){
            dp1[j] = dp2[j];
            if(j >= value[i]) dp1[j] = min(dp2[j], (dp2[j-value[i]] + weights[i] < 0)?LLONG_MAX:(dp2[j-value[i]] + weights[i]));
            else dp1[j] = min(dp1[j], weights[i]);
            if(dp1[j] <= w) ans = max(ans, j);
            // cout<<i<<sp<<j<<sp<<dp1[j]<<sp<<weights[i]<<sp<<value[i]<<sp<<dp2[j]<<sp<<dp2[j-value[i]]<<sp<<ans<<endl;
        }
    }
    cout<<ans;
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