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
     
    
     ll n,l=0,r=0, res=-10000000000; cin >> n;
     for (ll i =0,x; i < n ; i++){
          cin >> x ;v.pb(x);
     }
     // cout << "loule"<<endl;
    ll i =0;{
          ll c=0;
          map <ll,ll> occ;
           if (!occ[v[i]])
               {occ[v[i]]++;c++;}
          for (ll j =i+1; j < n ; j++){
                        
              
               if (!occ[v[j]])
                    {occ[v[j]]++;c++;}
               if (j-i-c>res){
                    l=i; r=j;
                    res= j-i-c;
                    //  cout << l+1<< " "<< r+1<<" "<< res << endl;
               }
               //  cout << i<< " "<< j<<" "<< res<<" c : " << c<< endl;
          }
     }
      cout << l+1<< " "<< r+1<< endl;
     //dbg(v);

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