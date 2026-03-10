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

const ll N = 1e3+5 , MOD =1e9+7, Q =1e10+3 ;
    
void solve () { 
    ll n , res = -1 , m , hesba =0; 
    cin >> n >> m ; 
    vi a(n), b(n )  ; 
    for( ll i= 0 ; i<n ; i++ )
        cin >> a[i] ; 
    // dbg(a) ; 
    for( ll i= 0 ; i<n ; i++ )
        cin >> b[i]; 
    for (ll i= 0 ;i<n ; i++ ) {
        if ( hesba + a[i] > m ); 
        else if (res == -1 )
            res = i ; 
        else if ( b[i]> b[res])
            res = i ; 
        hesba ++ ; 
    } 
    cout << (res==-1 ? res : ++ res)  <<endl; 

}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    FAST ;
    io() ;
    srand(time(0)) ;
    ll tt=1;
    cin >> tt ;   
    while (tt--)
        solve() ;
}