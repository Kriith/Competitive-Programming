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
    int a[n], b[n];
    lop(i, n){
        cin>>a[i];
        b[i] = a[i];
    }
    int mex = 0;
    sort(b, b+n);
    vi c;
    if(b[0] == 0){
        c.pb(1);
        lopp(i, n){
            if(b[i] > mex + 1){
                if(c[mex] < 2){
                    cout<<"-1\n";
                    return;
                }
                break;
            }
            else if(b[i] == mex+1){
                if(c[mex] < 2){
                    cout<<"-1\n";
                    return;
                }
                mex++;
                c.pb(mex);
            }
            else if(b[i] == mex){
                c[mex]++;
            }
        }
    }
    else{
        cout<<"2\n1 1\n"<<"2 "<<n<<endl;
        return;
    }
    vi d(mex+1, 0) ;
    lop(i, n){
        if(a[i] <= mex){
            c[a[i]]--;
            if(d[a[i]] == 0)
                d[a[i]] = i;
            else if(c[a[i]] > 0){
                d[a[i]] = i;
            }
            if(c[a[i]] < 1){
                cout<<"-1\n";
                return;
            }
        }
    }
    int max = d[0];
    lop(i, mex+1){
        if(d[i] == 0){
            cout<<"-1\n";
            return;
        }
        else if(d[i] > max)
            max = d[i];
    }
    cout<<"2\n1 "<<max+1<<endl<<max+2<<" "<<n<<endl;
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