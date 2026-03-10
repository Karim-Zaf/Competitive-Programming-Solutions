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
      ll n, mx=1, s=1; cin >> n ;
      vector <ll> v ;
      
      for (ll i =0,x ; i < n ; i++){
            cin >>x;
            v.push_back(x);}
          if ( n==1){cout << 0 << endl; return;}
      sort( v.begin(), v.end());
      //dbg(v);
      for  (ll i =1 ; i < n ; i++){
            if ( v[i-1]==v[i]){
                  s++;
                  mx=max(mx,s);
                  }
                  else s=1;
      }
      //if (  mx==1){cout << n << endl; return;}
      //if ( mx==n){cout << 0 << endl; return;}
      //cout << mx << endl;
      ll r = n-mx;
      ll res=r;
      ll clone= 0;
      while ( r >0){
            clone ++;
            r-=mx;
            mx+= mx;
      }
      cout << clone + res << endl;
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