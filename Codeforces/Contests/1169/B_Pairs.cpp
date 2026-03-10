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

const ll N = 1e5+5 , MOD =1e9+7, Q =1e10+3 ;

void solve () {
    ll n , m ,a, b ,init_x , init_y, new_x, new_y , ok = 0 ;
    cin >> n >> m ;
    vector <pair <ll,ll>>  v, ver, res ;
    for (ll i=0 ;i<m ; i++ )  {
        cin >> a >> b ; 
        v.pb( {a,b}) ; 
    }
    init_x  = v[0].F  , init_y = v[0].S; 
    for (ll i= 1 ;i<m ; i++ ){
        if ( v[i].F != init_x && v[i].S != init_x )
            ver.pb(v[i]) ; 
    }

    if (ver.size() <=1 ){yes return; }  
    else {
        ll sz_ver = ver.size() ; 
        new_x = ver[0].F, new_y = ver[0].S ; 
        for (ll i =1 ;i<sz_ver ; i++){
            ok = 1 ; 
            if ( ver[i].F != new_x && ver[i].S != new_x ){
                ok =0 ;
                break; 
            }
        }
        if ( ok ) {yes return ; }
        for (ll i =1 ;i<sz_ver ; i++){
            ok = 1 ; 
            if ( ver[i].F != new_y && ver[i].S != new_y ){
                ok =0 ;
                break; 
            }  
        }   
        if ( ok ) {yes return ; }
    }


    ver.clear() ; 
    for (ll i= 1 ;i<m ; i++ ){
        if ( v[i].F != init_y && v[i].S != init_y )
            ver.pb(v[i]) ; 
    }
    if (ver.size() <=1 ) {yes return ;} 
    else {
        ll sz_ver = ver.size() ; 
        new_x = ver[0].F, new_y = ver[0].S ; 
        for (ll i =1 ;i<sz_ver ; i++){
            ok = 1 ; 
            if ( ver[i].F != new_x && ver[i].S != new_x ){
                ok =0 ;
                break; 
            }
        }
        if ( ok ) {yes return ; }
        for (ll i =1 ;i<sz_ver ; i++){
            ok = 1 ; 
            if ( ver[i].F != new_y && ver[i].S != new_y ){
                ok =0 ;
                break; 
            }   
        } 
        if ( ok ) {yes return ; }
    }
    no 
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