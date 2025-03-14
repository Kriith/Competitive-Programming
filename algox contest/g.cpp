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
    ll n;
    cin>>n;
    int counter = 0;
    while(n%10 != 0 && n%10 != 5){ 
        n/=10;
        counter ++;
    }
    if(n%10 == 0){
        n/=10;
        while(n%10 != 0 && n%10 != 5){
            n/=10;
            counter ++;
        }
    }
    else{
        n/=10;
        while(n%10 != 2 && n%10 != 7 && n%10 != 0){
            n/=10;
            counter ++;
        }
        if(n%10 == 0){
            n/=10;
            counter ++;
            while(n%10 != 2 && n%10 != 7 && n%10 != 0 && n%10 != 5){
                n/=10;
                counter ++;
            }
        }
    }
    cout<<counter<<endl;
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