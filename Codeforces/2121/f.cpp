#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sp " "

void solve(){
    ll n, s, X;
    cin>>n>>s>>X;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    //logic: find subsegments with values <= x and sum = s
    //then find subsegments with values <= x - 1 and sum = s
    //subtracting the second from first will give our answer
    vector<ll> pf(n);
    pf[0] = a[0];
    for(int i = 1; i < n; i++) pf[i] = pf[i-1] + a[i];
    auto check = [&](int x){
        map<ll, int> cnt;
        cnt[0]++;
        ll ans = 0;
        for(int i = 0; i < n; i++){
            if(a[i] > x) cnt.clear();
            else ans += cnt[pf[i] - s];
            cnt[pf[i]]++;
        }
        return ans;
    };
    cout<<(check(X) - check(X-1))<<endl;
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