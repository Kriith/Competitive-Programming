#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using mint = map<int, int>;
using mll = map<ll, ll>;
using pi = pair<int, int>;

#define loop(i, a, b) for(int i = a; i<b; i++)
#define pool(i, a, b) for(int i = a; i>b; i--)
#define lop(i, n) for(int i = 0; i<n; i++)
#define lopp(i, n) for(int i = 1; i<n; i++)
#define eb emplace_back
#define ef emplace_front
#define pb pop_back
#define popf pop_front
#define ff first
#define ss second
#define nl "\n"
#define sp " "

void solve(){
    int n, c = 0, d = 0;
    cin>>n;
    int a[n];
    lop(i, n)cin>>a[i];
    int di = 0, dc = 0;
    lopp(i, n){
        if(a[i] < a[i-1]){
            di = i;
            dc++;
        }
    }
    // cout<<di<<sp<<dc<<sp;
    if(dc > 1){
        cout<<"No\n";
        return;
    }
    if(di == 0) cout<<"Yes\n";
    else{
        if(a[0] >= a[n-1]) cout<<"Yes\n";
        else cout<<"No\n";
    }
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