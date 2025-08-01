#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sp " "

void solve(){
    ll n;
    cin>>n;
    ll l = 1, r = n*n, q = (n*n + 1)/2, ans = 0;
    while(l <= r){
        ll m = (l + r)/2, t = 0;
        for(int i = 1; i <= n; i++) t += min(n, m/i);
        if(t >= q) ans = m, r = m - 1;
        else l = m + 1;
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