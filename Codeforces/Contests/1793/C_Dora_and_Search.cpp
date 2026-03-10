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
#define watch(x) cout << "\n" << (#x) << " is " << (x) << endl
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

vector <ll> vv, primes;
// map <ll,ll> mp;
set <ll> ss;
ll x;

void solve(){
    ll a ,n, b , l ,r , mn=1 , mx ;
    cin >> n;mx=n;
    map <ll,ll > mp;
    vi v(n+1) ;
    fr(i,1,n+1){
        cin >> v[i]; 
        mp[v[i]]=i;
    }
    // if ( v[n]==n&& v[1]==1 || v[1]==n&& v[n]==1){
    //     cout << -1 << endl ; return; 
    // }
    ll lef=1 , righ =n, ok=0 ;
    while ( lef <= righ  ){
        if ( mp[mx]==lef){lef++; mx--;; ok=1;}
        else if ( mp[mx]==righ){righ-- ; mx --; ok=1;}
        if (mp[mn]==lef){lef++; mn++ ; ok=1;}
        if (mp[mn]==righ){righ--; mn++; ok=1;}
        if (!ok){cout << lef << " " << righ<<endl; return;}
        ok=0;
    }

    // watch (lef ); 
    cout << -1 <<endl;


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
