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
    int n, m, k;
    cin>>n>>m>>k;
    vi v(k+1);
    vi a(k+1);
    vi b(k+1);
    int ctn = 0; 
    int ctm = 0;
    // int common = 0;
    lop(i, n){
        int x;
        cin>>x;
        if(x <= k && a[x] < 1){
            v[x]++;
            a[x]++;
            ctn++;
        }
    }
    lop(i, m){
        int x;
        cin>>x;
        if(x <= k && b[x] < 1){
            v[x]++;
            b[x]++;
            ctm++;
            // if(v[x] > 1){
            //     common++;
            // }
        }
    }
    if(ctn < k/2 || ctm < k/2){
        cout<<"NO\n";
        return;
    }
    // else if(abs(ctn - ctm) < common){
    //     cout<<"NO\n";
    //     return;
    // }
    else{
        lopp(i, k+1){
            if(v[i] == 0){
                cout<<"NO\n";
                return;
            }
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