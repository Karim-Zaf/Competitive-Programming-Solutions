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
 
void solve()
{
      ll n,x ; cin >>n>>x ;bool ok =0;
      vector <ll> v1 (n),v2(n);
      v1[0]=x; v2[0]=x;
      for ( int i =1;i< n;i++) {
            cin >> v1[i];
            v2[i]=v1[i]+v2[i-1];
            if (v1[i] <=v2[i-1] && v1[i] !=0 && !ok){
                  cout << -1 <<  endl;
                  ok=1;
            }
            
      
      }
      if (!ok)dbg(v2);
}
 
int main()
{
    FAST ;
    io() ;
    srand(time(0)) ;
    ll tt ; cin >> tt ;
    for(ll i = 1 ; i<=tt ; i++)
        solve() ;
}