#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
#define FAST ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define pb push_back
#define pi pair<ll,ll>
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define fr(i,a,b) for(ll i = a;i < (ll)b;i++)
#define rfr(i,a,b) for(ll i = a;i > (ll)b;i--)
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define INF (ll)(1e18)
void io(){ios::sync_with_stdio(false) ;cin.tie(NULL) ;}
void dbg(vector<ll> tab){for(auto it : tab) cout<<it<<" ";cout<<endl;}
void dbgg(pi p){cout<<p.F<<" "<<p.S<<endl;}
void dbgpi(vector<pi> tab){for(auto it : tab) dbgg(it) ;}

const ll N = 2*1e5+1;


map<string,vector<string>> graph;
map<string,int>vis;
vector <ll> v,vs;
map <ll,ll> mp;
set <ll> s;


void solve()
{
    ll n,a=0 ,mx=0,imx=0,m=0,im=0; cin >> n;
    for ( ll i = 0,x; i< n ; i++){
        cin >>x ;v.pb(x);a+=v[i];
        if ( x>mx){m=mx;mx=v[i]; imx=i;}
        else if ( x>=m){m=v[i]; im=i;}
    }
    for ( ll i = 0 ; i< n ; i++){
        if (a-v[i]-mx == mx&&i!=imx)vs.pb(i+1);
    }
    if (a-mx-m==m)vs.pb(imx+1);
    cout << vs.size()<<endl;
    dbg(vs);



}
int main()
{
    FAST ;
    io() ;
    srand(time(0)) ;
     ll tt=1;
       //cin >> tt;
    while (tt--)
        solve() ;
}



