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

void solve(){
    int n, a, b;
    cin>>n>>a>>b;
    if(2*a <= b)
        cout<<n*a<<nl;
    else{ 
        if (n%2 == 0) cout<<b*n/2<<nl;
        else cout<<(b*(n/2) + a)<<nl;
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