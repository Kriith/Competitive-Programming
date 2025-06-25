#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sp " "

void solve(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin>>a[i][j];

    int mx = 0;
    for(int i = 0; i < n; i++) mx = max(mx, *max_element(a[i].begin(), a[i].end()));
    int row = -1, col = -1, mxcnt = 0;
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = 0; j < m; j++) if(a[i][j] == mx) cnt++;
        if(cnt > mxcnt) mxcnt = cnt, row = i;
    }
    // cout<<n<<sp<<m<<endl;
    bool flg = 0;
    for(int i = 0; i < n; i++){
        if(i == row) continue;
        for(int j = 0; j < m; j++){
            // cout<<i<<sp<<row<<sp<<j<<sp<<col<<sp<<a[i][j]<<endl;
            if(a[i][j] == mx){
                if(col < 0) col = j;
                else if(j != col){ flg = 1; break; }
            }
        }
        if(flg) break;
    }
    if(!flg){ cout<<(--mx)<<endl; return; }
    row = col = -1, mxcnt = 0;
    for(int j = 0; j < m; j++){
        int cnt = 0;
        for(int i = 0; i < n; i++) if(a[i][j] == mx) cnt++;
        if(cnt > mxcnt) col = j, mxcnt = cnt;
    }
    for(int j = 0; j < m; j++){
        if(j == col) continue;
        for(int i = 0; i < n; i++){
            if(a[i][j] == mx){
                if(row < 0) row = i;
                else if(row != i){ cout<<mx<<endl; return; }
            }
        }
    }
    cout<<(--mx)<<endl;
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