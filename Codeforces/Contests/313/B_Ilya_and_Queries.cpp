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
void io(){ios::sync_with_stdio(false) ;cin.tie(NULL) ;}
void dbg(vector<ll> tab){for(auto it : tab) cout<<it<<" ";cout<<endl;}
void dbgg(pi p){cout<<p.F<<" "<<p.S<<endl;}
void dbgpi(vector<pi> tab){for(auto it : tab) dbgg(it) ;}

vector <ll> v;
map <ll,ll> mp;
set <ll> s;


void solve()
{
     string x; cin >> x ; 
     ll t ; cin >> t ;
     v.pb(0);
     for ( unsigned long long i =0 ; i<x.size()-1;i++)
          if (x[i]==x[i+1]) v.pb(v[v.size()-1]+1);
          else v.pb(v[v.size()-1]);
          // dbg(v);
     while ( t--){
          ll l , r,res=0 ; cin >> l>> r ;
               cout <<v[r-1]- v[l-1] << endl;
          
     }
}
 
int main()
{
//    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    FAST ;
    io() ;
    srand(time(0)) ;
     ll tt=1;
     //  cin >> tt;
 
    while (tt--)
        solve() ;
}