#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sp " "

void solve(){
    int n; string s;
    cin>>n>>s;
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += 1LL * i * (n - i + 1);
    }
    // cout<<ans<<sp;
    int pref[n+1];
    pref[0] = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') pref[i + 1] = pref[i] + 1;
        else pref[i + 1] = pref[i] - 1;
    }
    sort(pref, pref + n + 1);
    for(int i = 0; i <= n; i++) {
        ans += 1LL * pref[i] * (2 * i - n);
    }
    cout<<ans/2<<endl;
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