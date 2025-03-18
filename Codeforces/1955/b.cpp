#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using mint = map<int, int>;
using pi = pair<int, int>;

#define loop(i, a, b) for(int i = a; i<b; i++)
#define pool(i, a, b) for(int i = a; i>b; i--)
#define lop(i, n) for(int i = 0; i<n; i++)
#define lopp(i, n) for(int i = 1; i<n; i++)
#define pb emplace_back
#define popb pop_back
#define ff first
#define ss second
#define nl "\n"

// const int MAX = 10e9;

void solve(){
    int n, c, d;
    cin>>n>>c>>d;
    mint mp;
    int m = INT_MAX;
    lop(i, n*n){
        int x;
        cin>>x;
        mp[x]++;
        if(x <= m)
            m = x;
    }
    // int a[n][n];
    // a[0][0] = m;za
    // lopp(i, n){
    //     a[i][0] = a[i-1][0] + c;
    //     mp[a[i][0]]++;
    //     lopp(j, n){
    //         a[i][j] = a[i][j-1] + d;
    //         mp[a[i][j]]++;
    //     }
    // }
    lop(i, n){
        lop(j, n){
            if(mp[m + (i)*c + j*d] <= 0){
                cout<<"NO\n";
                return;
            }
            mp[m + (i)*c + j*d]--;
        }
    }
    cout<<"YES\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}