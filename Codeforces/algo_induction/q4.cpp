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
    string s;
    cin>>s;
    int ak = 5;int bk = 5;
    int ag = 0;int bg = 0;
    int i = 0;
    lop(i, 10){
        if(i%2 == 0){
            ak--;
            if(s[i] == '1') ag++;
        }
        else{
            bk--;
            if(s[i] == '1') bg++;
        }
        if(((ag > bg) && (ag - bg > bk)) || ((ag < bg) && (bg - ag > ak))){
            cout<<i+1<<nl;
            return;
        }
    }
    cout<<"10\n";
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