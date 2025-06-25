#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sp " "

void solve(){
    int n;
    cin>>n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < n; i++) cin>>b[i];

    vector<pair<int, int>> ans;
    for(int j = 0; j < n - 1; j++){
        bool flg = 0;
        for(int i = 0; i < n - j - 1; i++){
            if(a[i] > a[i+1]){
                flg = 1;
                ans.push_back({1, i + 1});
                swap(a[i], a[i+1]);
            }
            if(b[i] > b[i+1]){
                flg = 1;
                ans.push_back({2, i + 1});
                swap(b[i], b[i+1]);
            }
        }
        if(!flg) break;
    }
    for(int i = 0; i < n; i++){
        if(a[i] > b[i]){
            ans.push_back({3, i+1});
            swap(a[i], b[i]);
        }
    }
    cout<<ans.size()<<endl;
    for(auto i: ans) cout<<i.first<<sp<<i.second<<endl;
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