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
 
map <ll,ll> mp;
vector<ll> v,res;

void solve()
{
     v.clear();
     ll n,mx1,mx2; cin  >>n>>mx1>>mx2;v.pb(mx1);v.pb(mx2);
     if (mx2>mx1){
          ll aux=mx1;
          mx1=mx2;mx2=aux;
     }
     for (int i=2; i<n;i++){
          ll x ; cin >>x;
          v.pb(x);
          if (x>mx1){mx2=mx1;mx1=x;}
          else if (x>mx2) mx2=x;
     }
    // sort(v.begin(),v.end());
     
     for (int i=0; i<n;i++)
          if (v[i]!=mx1)cout<< v[i]-mx1 << " ";
          else cout << mx1-mx2<< " ";
          cout << endl;

    
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