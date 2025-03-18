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
    int c = 0;
    int a = 0;
    lop(i, n){
        string s;
        cin>>s;
        lop(j, n){
            if(s[j] == '1'){
                c++;
            }
            // cout<<c;
        }
        if(c == 1)
            a = 1;
        // cout<<a<<"\n";
        c = 0;
    }
    if(a == 0)
        cout<<"SQUARE\n";
    else
        cout<<"TRIANGLE\n";
    return;
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