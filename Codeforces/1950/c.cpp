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
    int a, b;
    char c;
    cin>>a>>c>>b;
    if(a == 0){
        if(b>9)
        cout<<"12:"<<b<<" AM\n";
        else
            cout<<"12:0"<<b<<" AM\n";
    }
    else if(a<12){
        if(b>9 && a>9)
        cout<<a<<":"<<b<<" AM\n";
        else if(a<=9){
            if(b<=9)
                cout<<"0"<<a<<":0"<<b<<" AM\n";
            else
                cout<<"0"<<a<<":"<<b<<" AM\n";
        }
        else
            cout<<a<<":0"<<b<<" AM\n";
    }
    else if(a == 12){
        if(b>9)
        cout<<"12:"<<b<<" PM\n";
        else
            cout<<"12:0"<<b<<" PM\n";
    }
    else{ 
        a -= 12;   
        if(b>9 && a>9)
        cout<<a<<":"<<b<<" PM\n";
        else if(a<=9){
            if(b<=9)
                cout<<"0"<<a<<":0"<<b<<" PM\n";
            else
                cout<<"0"<<a<<":"<<b<<" PM\n";
        }
        else
            cout<<a<<":0"<<b<<" PM\n";
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