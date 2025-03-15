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
#define eb emplace_back
#define ef emplace_front
#define pb pop_back
#define popf pop_front
#define ff first
#define ss second
#define nl "\n"
#define sp " "

void solve(){
    int n;
    cin>>n;
    vll c(n);
    ll odd{0}, even{0}, negmax{INT_MIN};
    bool flag = 1;
    lop(i, n){
        cin>>c[i];
        if(i&1 && c[i] > 0){
            odd += c[i];
            flag = 0;
        }
        else if(!(i&1) && c[i] > 0){
            even += c[i];
            flag = 0;
        }
        if(c[i] <= 0 && c[i] >= negmax) negmax = c[i];
    }
    if(flag) cout<<negmax<<nl;
    else cout<<max(odd, even)<<nl;
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