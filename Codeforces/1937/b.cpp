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
    string s1, s2;
    char ans[n+1];
    cin>>s1>>s2;
    int t = 1,a = 0;
    lopp(i, n){
        if(a == 0){
            ans[i-1] = s1[i-1];
            if(s1[i] > s2[i-1]){
                a = 1;
                ans[i] = s2[i-1];
            }
            else if(s1[i] == s2[i-1]){
                t++;
            }
            else{
                t = 1;
            }
        }
        else{
            ans[i] = s2[i-1];
        }
    }
    if(a == 0)
        ans[n-1] = s1[n-1];
    ans[n] = s2[n-1];
    lop(i, n+1)
        cout<<ans[i];
    cout<<"\n"<<t<<"\n";
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