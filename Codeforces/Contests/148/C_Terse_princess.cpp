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
    ll n, a ,l,r, b,s; cin >> n>>a >> b;
    
     if ( !a && !b){
          while ( n--)
          cout << n+1 << " ";
          return;
     }
     if ( b){
          for ( ll i =0 ; i<b ; i++){
                if ( !i){ v.pb(1);v.pb(2);s=2;}
                  else {s=s*2+1;v.pb(s);}
             }
            
             for ( ll i =0 ; i<a; i++){
                       v.pb(++s);
             }
             
 
             for (ll i= v.size(); i< n;i++)
                    v.pb(s);
               // dbg(v);
             
     }
     else {
            for ( ll i =0 ; i<=a; i++){
                  if ( !i){ v.pb(2);v.pb(1);l=2;}
                      else { l++; v.pb(l);}
             }
                for (ll i= v.size(); i< n;i++)
                    v.pb(l);
           
     }
     if ( v.size()!=n)cout << -1;
     else dbg(v);
     
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