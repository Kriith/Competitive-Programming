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
    int a[n+1];
    cin>>a[1];
    vi difl, difr;
    loop(i, 1, n+1){
        cin>>a[i];
        if(a[i] != a[i-1]){
            difl.pb(i);
            difr.pb(i-1);
        }
    }
    int q;
    cin>>q;
    while(q--){
        int l, r;
        cin>>l>>r;
        if(l-r < 2){
            cout<<"-1 -1\n";
        }
        else{
            lop(j, difl.size()){
                if(l < difl[j] && difl[j] <= r){
                    cout<<j<<" "<<j-1<<"\n";
                    break;
                }
                else if(l <= difr[j] && difr[j] < r){
                    cout<<j<<" "<<j+1<<"\n";
                    break;
                }
            }
        }
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