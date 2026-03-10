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
    v.clear();mp.clear();res.clear(); ll n,x ; cin >> n ; 
    for( ll i =1; i <=n;i++){
         cin >> x ; 
         v.pb(x);
    }
    //dbg(v);
    ll mx=0, mx_nb=0;
    for ( ll i =0; i < n ;i++){
         mp[v[i]]=mp[v[i]-1]+1;
         if (mp[v[i]]>mx ){
               mx=mp[v[i]];
               mx_nb= v[i];
         }
    }
    
    cout << mx << endl;
     for ( ll i =n-1; i >= 0;i--){
          if ( v[i] == mx_nb){
               res.pb(i+1); mx_nb--; 
          }
     }
     sort ( res.begin (), res.end());
     for ( auto x : res)cout << x << " ";
    //for(auto it =mp.cbegin();it != mp.cend();it++)
        // cout << it->first << "   "<< it ->second << endl;
         
    
    
}
 
int main()
{
    FAST ;
    io() ;
    srand(time(0)) ;
    //ll tt; cin >> tt;
 
    //while (tt--)
        solve() ;
}