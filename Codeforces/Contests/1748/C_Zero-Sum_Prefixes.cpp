#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll mod = 1e9+7, N = 2e6+7, M = 2e6+7, INF = INT_MAX/10;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);ll ans = 1;while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}return ans;}
 
map <ll, ll > mp; 
 
void solve(){
     ll n,mx=0, c=0; cin >> n ;
     vector <ll> t(n+1), somme (n+1,0);
     
     for(ll i=1; i <= n; i++){
          cin >> t[i];
          somme[i]=somme[i-1]+t[i];
     }
     map <ll, ll> mp;
     for(ll i=n; i >=1; i--){
          mp[somme[i]]++;
          mx= max( mx , mp [somme[i]]);
          if (!t[i]) {
               c+=mx;
               mx=0;
               mp.clear();
          }
     }
     /*
     if (!j){cout << c << endl;return;}
     
     while (j < n){
          
          ll i=j+1;
          while( i <n && t[i])
               i++;

          ll mx =0;
          for (ll l=j; l<i ; l++){
               cin >> t[l];
               somme[l]=somme[l-1]+t[l];
               mp[somme[l]]++;
               mx= max( mx , mp [somme[l]]);
          }
          c+=mx;
          j=i;
     }
     
     for(ll occ=0,i= n-1; i>=0; i--){
           mp[s]++;
         
         occ=max(occ, mp[s]);
          s-=t[i];
          if ( t[i]==0){
               c+=occ;
               occ=0;
               mp.clear();
               }
          
         //else if ( t[i]==0){x++;b=i;}
          //else if ( s==0)c++;
     }*/
     cout << c+mp[0] << endl;
}
 
 
 
 
signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}