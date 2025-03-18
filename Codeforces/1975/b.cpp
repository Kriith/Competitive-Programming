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

// map<ll, vector<ll>> m;

// void div(ll n){
//     for(int i = 1; i <= sqrt(n); i++){
//         if(n%i == 0){
//             m[n].eb(i);
//         }
//     }
// }

void solve(){
    ll n;
    cin>>n;
    ll a[n];
    bool flag = 0;
    lop(i, n){
        cin>>a[i];
        if(a[i] == 1)
            flag = 1;
    }
    if(flag){
        cout<<"Yes\n";
        return;
    }
    flag = 1;
    sort(a, a+n);
    // int j = 1;
    // if(a[0] == a[j]){
    //     // cout<<"iin";
    //     int i = 2;
    //     while(a[j] == a[0]){
    //         // cout<<i<<sp;
    //         if(a[i] != a[0])
    //             j = i;
    //         i++;
    //     }
    // }
    // cout<<a[0]<<sp<<a[j]<<nl;
    vll v;
    lop(i, n){
        if(a[i]%a[0] != 0)
            v.eb(a[i]);
    }
    lop(i, v.size()){
        if(v[i]%v[0] != 0)
            flag = 0;
    }
    if(!flag) cout<<"No\n";
    else cout<<"Yes\n";
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