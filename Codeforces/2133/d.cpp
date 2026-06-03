#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sp " "

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    ll curr[2] = {0, 0}, prev[2] = {0, 0};
    for(int i = n-1; i > 0; i--){
        curr[0] = max(0LL, 1LL*(a[i] - i)) + prev[1];
        curr[1] = min(a[i] + prev[1] - 1, prev[0] + a[i]) + 0LL;
        prev[0] = curr[0], prev[1] = curr[1];
    }
    cout<<a[0] + min(curr[0], curr[1])<<endl;
    return;
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