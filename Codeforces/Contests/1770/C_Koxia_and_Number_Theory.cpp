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

const ll N = 2*1e5+1;

map<string,vector<string>> graph;
map<string,int>vis;
vector <ll> v ,vs , primes;
map <ll,ll> mp;
set <ll> s;


void primevi(){
    fr(i,2,100){
        fr(j,2,i+1){
            if (j==i) primes.pb(i);
            if ( i%j ==0) break;
        }
    }
}

void solve()
{
    ll ok=1, n,x ; cin >> n; v.clear();mp.clear();
    fr(i,0,n){
        cin >> x ; v.pb(x);
        mp[x]++; if (mp[x]>1)ok=0;
    }
    if (!ok){no return;}
    for (auto p: primes){
          vi freq(p,0);
          fr(j,0,n)
               freq[v[j]%p]++;
          sort (all(freq));
          if (freq[0]>1){no return;}
    }
    yes
}
int main()
{
    #ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
     #endif
    primevi();
     FAST ;
     io() ;
     srand(time(0)) ;
     ll tt=1;
     cin >> tt;
     while (tt--)
          solve() ;
}
