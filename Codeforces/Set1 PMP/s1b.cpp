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
    ll s, n, flag = 0;
    cin>>s>>n;
    vector<pair<int, int>> p(n);
    lop(i, n){ 
        cin>>p[i].ff>>p[i].ss;
    }
    sort(p.begin(), p.end());
    lop(i, n){
        if(s > p[i].ff)
            s+= p[i].ss;
        else{
            cout<<"NO";
            return;
        }
    }
    cout<<"YES";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // int t;
    // cin>>t;
    // while(t--)
        solve();
    return 0;
}