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
     ll n,x, imax=0,imin=0 ;cin >> n ; v.clear(); 
     ll i =1 ;
     int t [n][n];
     for(ll i=1,j=0,x=0,y=0,a=1;j<=n*n;a++){
          if (!(x%2))
               t[x][y]=n*n-a+1;
          else 
               t[x][n-y-1]=n*n -a+1;
          y++;
          if (y>=n){x++;y=0;}
          if (x>=n)break;
          if (!(x%2))
               t[x][y]=a;
          else 
               t[x][n-y-1]=a;
          y++;
          if (y>=n){x++;y=0;}
          if (x>=n)break;
     }
     fr(i,0,n){
          fr(j,0,n) cout << t[i][j]<<" "; cout << endl;
     }
}
int main()
{
    FAST ;
    io() ;
    srand(time(0)) ;
     ll tt=1;
       cin >> tt;
    while (tt--)
        solve() ;
}