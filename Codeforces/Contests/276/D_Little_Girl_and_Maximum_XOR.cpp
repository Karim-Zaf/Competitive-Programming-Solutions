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
#define watch(x) cout << "\n" << (#x) << " is " << (x) << endl
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'
void io(){ios::sync_with_stdio(false) ;cin.tie(NULL) ;}
void dbg(vector<ll> tab){for(auto it : tab) cout<<it<<" ";cout<<endl;}
void dbgg(pi p){cout<<p.F<<" "<<p.S<<endl;}
void dbgpi(vector<pi> tab){for(auto it : tab) dbgg(it) ;}

const ll mod =  998244353 , N = 1e5+3;


ll fact ( ll n ){
    if ( n ==  0)
        return 1;
    ll res =1 ;
    for ( ll i=1 ; i<=n; i++)
        res =(res*i)%mod;
    return res;
}

ll combinaison (ll n ,ll p){
    return (fact(n)%mod)/(fact(p)*(fact(n-p)%mod)%mod);
}
void solve(){
    ll l , r , ok=0 , res=0 ;
    cin >> l >>  r;
    for (ll i =60  ; i>=0 ;i--){
        ll p = 1ll <<i;
        if ((r & p )!=(l&p) && !ok)
            ok=1;
        if (ok)
            res+=p;
    }
   cout << res <<endl;

}

int main()
{
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
