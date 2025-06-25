#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sp " "

void solve(){
    int n, m;
    cin>>n>>m;
    string a, b;
    a = to_string(n), b = to_string(m);
    n = a.size();

    bool flg = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == b[i]){
            if(flg) break;
            ans += 2;
        }
        else if(a[i] + 1 == b[i]){
            if(flg) break;
            ans++;
            flg = 1;
        }
        //for the case 199 & 201
        else if(a[i] > b[i] && a[i] - b[i] == 9) ans++;
        else break;
    }
    cout<<ans<<endl;
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