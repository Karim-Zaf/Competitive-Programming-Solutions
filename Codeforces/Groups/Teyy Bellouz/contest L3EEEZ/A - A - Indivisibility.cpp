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
#define watch(x) cout << (#x) << " is " << (x) << endl
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

const ll N = 1e5 , mod =1e9+7, Q =1e5+3 ;

void solve(){
    ll n , res = 0; 
    cin >> n ;
    res=n/2+ (n/3 -n/6+n/30+n/42)+
    (n/5 -n/10-n/15+n/70+n/105)+
    (n/7-n/14-n/35-n/21-n/210);
    // ll v []={2,3,5,7};
    // for (ll i=0 ; i<4; i++){
    //     ll x =n ; 
    //     res += n/v[i];
    //     x/=v[i];
    //     for (ll j=0 ;j<i; j++){
    //         if ( x%v[i])
    //         res-=x/v[j];

    //         x/=v[j];
    //     }
    // }
    cout << n-res <<endl;
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
