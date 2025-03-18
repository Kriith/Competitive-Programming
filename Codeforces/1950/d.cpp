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

vi bd;

bool check(int n){
    int len = bd.size();
    lop(i, len){
        if(bd[i] == n)
            return true;
    }
    return false;
}

void solve(){
    int n;
    cin>>n;
    int len = bd.size(), t= n;
    bool f = 0;
    lop(i, len){
        t = n;
        f = 0;
        if(t%bd[i] == 0){
            while(t>0){
                if(check(t) || check(t/bd[i])){
                    f = 1;
                    break;
                }
                t /= bd[i];
            }
            if(f){
                cout<<"YES\n";
                break;
            }
        }
    }
    if(!f) cout<<"NO\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 0, f = 0;
    lopp(i, 10000){
        t = i;
        f = 0;
        while(t>0){
            if(t%10 > 1){
                f++;
                break;
            }
            else t/=10;
        }
        if(!f){
            bd.pb(i);
            // cout<<i<<nl;
        }
    }
    int tt;
    cin>>tt;
    while(tt--)
        solve();
    return 0;
}