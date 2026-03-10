//  (1/0+) WINS
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
#define FAST ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define pb push_back
#define pi pair<ll,ll>
#define vi vector<ll>
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define fr(i,a,b) for(ll i = a;i < (ll)b;i++)
#define rfr(i,a,b) for(ll i = a;i > (ll)b;i--)
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define INF (ll)(1e18)
void io(){ios::sync_with_stdio(false) ;cin.tie(NULL) ;}
void dbg(vector<ll> tab){for(auto it : tab) cout<<it<<" ";cout<<endl;}
void dbgg(pi p){cout<<p.F<<" "<<p.S<<endl;}
void dbgmp(map<ll,ll> mp){for(auto p: mp) cout<<p.F<<" "<<p.S<<endl;}
void dbgpi(vector<pi> tab){for(auto it : tab) dbgg(it) ;}

const ll N = 1e5+7 , mod =1e9+7, Q =1e5+3 ;

void solve(){
    ll n, res = 0 , k , i =0 ; 
    cin >> n  ;
    vi v(n) , a , b; 
    vi t[9]; 
    for (ll i=0 ;i<n ; i++){
        cin >> v[i];
        t[v[i]%9].pb(v[i]);
    }
    for (ll i = 0 ; i<9; i++ ){
        ll j = 0 ;
        sort(all(t[i]));
        while (j< t[i].size()){
            if (t[i][j]==t[i][j-1]+9 && j >0)
                j++;
            if (j<t[i].size())
                res++;
            j++;
        }
    }

    cout << res<<endl;


    // for (ll i= 0 ; i<n ; i++){
    //     cin >> v[i];
    // }
    // sort (all(v));
    // // dbg(v);
    // for (ll i=0 ;i<n ; i++){
    //     ll pos = lower_bound(all(v), v[i]-9 ) -v.begin();
    //     // watch(pos);
    //     if (pos <n && v[pos]==v[i]-9){
    //         ll pos1 = lower_bound(all(a), v[i]-9 ) -a.begin();
    //         ll pos2 = lower_bound(all(b), v[i]-9 ) -b.begin();
    //         if ( pos1<a.size()&& a[pos1]!=v[i]-9)
    //             a.pb(v[i]);
    //         else if ( pos2<b.size()&& b[pos2]!=v[i]-9){
    //             b.pb(v[i]);

    //         sort(all(a));
    //         sort(all(b));
    //     }
    //     else {
    //         a.pb(v[i]);
    //         b.pb(v[i]);
    //         sort(all(a));
    //         sort(all(b));
    //     }
    //     // dbg(a);
    //     // dbg(b);
    // }
    // // dbg(a);
    // // dbg(b);
    // cout <<max (a.size(),b.size()) <<endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    FAST ;
    io() ;
    srand(time(0)) ;
    ll tt=1;
    // cin >> tt;
    while (tt--)
        solve() ;
}
