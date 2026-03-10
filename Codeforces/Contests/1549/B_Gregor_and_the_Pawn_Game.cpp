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

const ll N = 1e2;

vector <ll> v;
map <ll,ll> mp;
set <ll> s;

void solve()
{
     ll n,res=0 ;string a,b;cin >>n>> a >> b ;
     for ( ll i =0 ; i < n;i++){
          if (b[i]=='1'&&a[i]=='0'){b[i]='0';res++;}
          if (b[i+1]=='1'&&a[i+1]=='0'&&i<n){b[i+1]='0';res++;}
          if (a[i]=='1'&&b[i+1]=='1'&&i<n){res++;a[i]='0'; b[i+1]='0';}
          if (a[i+1]=='1'&&b[i]=='1'&&i<n){res++;a[i+1]='0'; b[i]='0';}
     }
     cout << res << endl;
     
     
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
      cin >> tt;
    while (tt--)
        solve() ;
}



