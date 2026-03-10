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
     v.clear();
    ll n , k ;cin >> n >> k ; ll pref[k]={0};
     for (ll i =0,x ; i < k ; i++){
          cin >> x ; v.pb ( x);
     }
     if (k==1){yes return;}
     pref[0]=v[0];
     for (ll i =1 ; i <=k-1 ; i++){
          pref [i]=v[i]-v[i-1];
          if (i!=1 && pref[i]<pref[i-1]){no return;}
     }
     if (k>1 && v[0]-pref[1]*(n-k)>pref[1]){no return;}
     yes
     
     // (auto x : pref){
     //      cout << x << " ";
     // }
     // cout << endl;
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



