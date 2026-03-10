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
void io(){ios::sync_with_stdio(false) ;cin.tie(NULL) ;//freopen("problem1.in","r",stdin) ;freopen("problem1.out","w",stdout) ;
}
void dbg(vector<ll> tab){for(auto it : tab) cout<<it<<" ";cout<<endl;}
void dbgg(pi p){cout<<p.F<<" "<<p.S<<endl;}
void dbgpi(vector<pi> tab){for(auto it : tab) dbgg(it) ;}
 
map <ll,ll> mp,occ;
vector<ll> v,res;

ll pgcd ( ll a, ll b){
     ll r;
    while(b != 0)
    {
      r = a%b;
      a = b;
      b = r; 
    }
    return a;
}
void solve()
{
     v.clear();
     occ.clear();
     ll n, mx=0,x,res=0; cin >> n ;
     while ( n--){
          cin >> x;
          res = __gcd (res,x);
          mx = max (mx,x);
     }
      cout << mx/res<<endl;
     
}
 
int main()
{
    FAST ;
    io() ;
    srand(time(0)) ;
    ll tt; cin >> tt;
     while (tt--)
        solve() ;
}