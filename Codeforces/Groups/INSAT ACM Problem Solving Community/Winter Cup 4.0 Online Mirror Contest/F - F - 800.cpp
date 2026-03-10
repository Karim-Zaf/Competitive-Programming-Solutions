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
 
ll N = 1e9+7;
void solve(){
    ll n ,m ; char  c;
    ll ok =1  ;
    cin >> n >> m >> c ;
    char t[n][m]; 
    for ( ll i =0 ; i< n ;i++){
        for ( ll j =0 ; j< m ;j++){
            cin >> t[i][j];
            if ( t[i][j]!=c)ok =0;
        }
    }
    if ( ok ){yes return;}
    if ( m==1 && n>1){
            no return;
        }
    for ( ll j = 1 ; j <m-1 ; j++)
        if ( t[n-1][j]!=c ){
            no return;
        }
    yes
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