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
#define watch(x) cout << (#x) << " is " << (x) << endl
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

const ll N = 1e6+3;

// map<string,vector<string>> graph;
// map<string,int>vis;
// vector <ll> v, vs ,pre, primes;
// map <ll,ll> mp,par;
// set <ll> s;
ll x,y;

void solve()
{
    ll n , a , b , res=1 ;
    cin >> n;
    // string x; 
    // cin >> x; 
    // map <char,ll> mp, pp;
    // int le= x.size();
    // fr ( i, 0 ,le ){
    //     mp[x[i]]++;
    // }
    // rfr(i,le-1,0){
    //     if( pp[x[i]])
    //         for (char z = x[i]; z<'9'; z++){

    //         }
    //     pp[x[i]]=1;
    // }
    vi v(n);
    fr(i,0,n){
        cin >> v[i];
    }
    ll mx= v[0];
    fr(i,1,n){
        ll ok=1;
        if (v[i]>mx)res++;
        mx= max ( mx,v[i]);
}
    cout << res << endl;
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
     // cin >> tt;
     while (tt--)
          solve() ;
}