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
#define pb push_back
#define popb pop_back
#define ff first
#define ss second

void solve(){
    ll w, h, kx0, kxh, ky0, kyh;
    cin>>w>>h>>kx0;
    ll x0[kx0];
    lop(i, kx0)
        cin>>x0[i];
    cin>>kxh;
    ll xh[kxh];
    lop(i, kxh)
        cin>>xh[i];
    cin>>ky0;
    ll y0[ky0];
    lop(i, ky0)
        cin>>y0[i];
    cin>>kyh;
    ll yh[kyh];
    lop(i, kyh)
        cin>>yh[i];
    ll areax= max((x0[kx0-1] - x0[0]), (xh[kxh-1], xh[0]))*h;
    ll areay = max((y0[ky0-1] - y0[0]), (yh[kyh-1], yh[0]))*w;
    cout<<max(areax, areay)<<endl;
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