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
ll mx= 1;
void solve(){
    ll n ; cin >> n;
    for ( ll i=n+1; i<1e11; i++){
        ll z = i;
        ll mx= 1;
        vi e(10);
        while ( z){
            ll r= z%10;
            e[r]++;
            z/=10;
            mx=max(mx , e[r]);
        }
        ll ok =1;
        for (auto l : e){
            if (l !=0 && l != mx)ok =0; 
        }
        if (ok){cout << i << endl; return;}
    }
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
