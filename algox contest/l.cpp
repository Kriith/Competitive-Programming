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
    int n, d;
    cin>>n>>d;
    int p[n];
    lop(i, n){
        cin>>p[i];
    }
    sort(p, p+n);
    int ans = 0, temp = 0, m = n;
    while(m>0){
        // temp = (d+p[n-1]-1)/p[n-1];
        // cout<<(d+p[n-1]-1)/p[n-1]<<endl;
        temp = (int)((double)d/p[n-1] + 1.0);
        // cout<<temp<<" ";
        if(temp > m){
            cout<<ans<<endl;
            return;
        }
        else{
            ans ++;
            m -= temp;
            n--;
        }
    }
    cout<<ans<<endl;
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