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
#define pb push_back
#define popb pop_back
#define ff first
#define ss second

void solve(){
    int n;
    cin>>n;
    int a[10] = {0, 1, 3, 6, 10, 15, 21, 28, 36, 45};
    // string s;
    // cin>>s;
    // ll sum = a[s[0] - 48] + ()
    // lopp(i, s.size()){
    //     sum += a[s[i] - 48] + (int)pow(10, i)*45* 
    // }
    ll sum = a[n%10] + (n/10)*45;
    cout<<sum<<" ";
    lopp(i, (int)log10(n)+1){
        int d = (int)pow(10, i);
        // cout<<d<<" ";
        cout<<d<<" "<<(n/d - (n/(d*10))*10)<<" "<<(n/d)*45<<" "<<(n%(d/10) + 1)<<" ";
        sum += (a[n/d - (n/(d*10))*10] + (n/d)*45)*(n%(d/10) + 1);
    }
    // cout<<"\n";
    cout<<sum<<"\n";
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