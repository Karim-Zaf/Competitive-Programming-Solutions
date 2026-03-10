#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
#define FAST ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define pb push_back
#define pi pair<ll,ll>
#define vi vector<ll>
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define fr(i,a,b) for(ll i = a;i < (ll)b;i++)
#define rfr(i,a,b) for(ll i = a;i > (ll)b;i--)
#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define INF (ll)(1e18)
void io(){ios::sync_with_stdio(false) ;cin.tie(NULL) ;}
void dbg(vector<ll> tab){for(auto it : tab) cout<<it<<" ";cout<<endl;}
void dbgg(pi p){cout<<p.F<<" "<<p.S<<endl;}
void dbgpi(vector<pi> tab){for(auto it : tab) dbgg(it) ;}

const ll N = 1e5+3;

map<string,vector<string>> graph;
map<string,int>vis;
vector <ll> v ,vs ,pre, primes;
map <ll,ll> mp;
set <ll> s;
ll x;
vi facteurs ( ll n){
     vi f;
     for ( ll i = 0 ; i<primes.size() ;i++){
          if(primes[i]*primes[i]>n) break ;
          if(n%primes[i]) continue ;
          f.pb(primes[i]);
          while(!(n % primes[i])){
            n /= primes[i];
        }
     }
     if ( n>1)f.pb(n);
     return f;
}

void pri () {
     int Maxx = 1e9 ;
    vector<int> pr(N , 0) ;
    for(ll i = 2 ; i*i<=Maxx ; i++){
        if(!pr[i]){
            primes.pb(i) ;
            for(ll j = i+i ; j*j<=Maxx ; j+=i){
                pr[j] = i ;
            }
        }
    }
}
void solve(){
     ll n , i=0,mx=0; cin >> n   ;v.clear(); mp.clear();
     fr(i,0,n){cin >> x ; v. pb ( x);mx =max(mx,x);}
     fr (i ,0,n ){
          vi p =facteurs(v[i]);
          // dbg (p);
          for (auto h:p){
               mp[h]++;
               if (mp[h]>=2){yes return;}
          }
     }
     no
}
int main()
{
    //#ifndef ONLINE_JUDGE
     //freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
     //#endif
     FAST ;
     io() ;
     srand(time(0)) ;
     ll tt=1;
     pri();
     //dbg(primes);
     cin >> tt;
     while (tt--)
          solve() ;
}
