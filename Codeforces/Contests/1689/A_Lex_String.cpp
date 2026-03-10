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
 
const ll N = 1e5+3, mod= 1e9 +7;
 
vector <ll> vv, primes;
map <ll,ll> mp;
set <ll> ss;
vector <ll> path , par(N), graph [N];
bool vis[N] ;
ll x, n,  k =1  ,ok =0 ;
  
void solve(){
    ll n ,m ,k ; 
    string a , b, c="";
    cin >> n>>m>> k>> a >> b;
    sort (all ( a)); 
    sort (all ( b));
    ll j =0, s=0;

    while (a!="" && b!=""){
        s =0 ;
        while ( a!="" && a[0]<b[0] && s<k || j==k && s<k && !s  ){
            s++;
            c+=a[0];
            a.erase(0,1);
        }
        if (a=="" || b=="") break;
        j=0;
        while ( b!="" && a[0]>b[0] && j<k || s==k && j<k && !j ){
            j++;
            c+=b[0];
            b.erase(0,1);
        }
        if (a=="" || b=="") break;
    }  
    cout << c << endl;

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