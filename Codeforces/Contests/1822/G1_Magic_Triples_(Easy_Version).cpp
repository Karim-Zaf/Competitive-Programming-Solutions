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

const ll N = 1e6+5 , MOD =1e9+7, Q =1e10+3 ;


void solve () { 
    ll n, res = 0  ,x, mx =-INF; 
    cin >> n  ; 
    map<ll,ll> mp ; 
    for (ll i=  0; i<n ; i++ ){
        cin >>x ; 
        mp[x]++ ;
        mx = max( mx , x) ;   
    }  
    for (auto p  : mp ){
        ll now = p.F ; 
        for (ll e = 1 ; e*e <= mx ; e++){
            if ( now % e ==0 && now % (e*e)==0) {
                ll i= mp[now] ; 
                ll j= mp[now/e] ; 
                ll k= mp[now/(e*e)] ;
                if (now ==now/e) {
                    if ( j>=1 )
                        j-- ; 
                        else continue ; 
                } 
                if (now/(e*e)== now/e && now/(e*e)==now){
                    if (k>=2)
                        k-=2 ;  
                }
                else if (now/(e*e)== now/e|| now/(e*e)==now){
                    if ( k >= 1 ) k-- ; 
                    else continue ; 
                }
                res+= i*j*k ;
            }
        }
    }
    cout << res << endl; 


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