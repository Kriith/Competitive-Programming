#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sp " "

void solve(){
    int n;
    cin>>n;
    vector<int> a(n), b(n);
    for(auto& i: a) cin>>i;
    for(auto& i: b) cin>>i;
    //changing b to its prefix min
    for(int i = 0; i < n - 1; i++) b[i+1] = min(b[i], b[i+1]);
    auto check = [&](int m)->bool{
        if(m == 0) return 1;
        int B = b[n - m], bad = 0, good = 0;
        for(int i = 0; i < m; i++) bad += (a[i] < B);
        for(int i = m; i < n; i++) good += (a[i] > B);
        if(bad == 0) return 1;
        if(bad == 1) return good > 0;
        return 0;
    };
    int l = 0, r = n, ans = 0;
    while(l <= r){
        int m = (r+l)/2;
        if(check(m)) l = m + 1, ans = m;
        else r = m - 1;
    }
    cout<<ans<<endl;
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