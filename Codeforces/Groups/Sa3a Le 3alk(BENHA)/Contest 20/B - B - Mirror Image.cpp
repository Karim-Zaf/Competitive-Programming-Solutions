//  (1/0+) WINS
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
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define INF (ll)(1e18)
void io(){ios::sync_with_stdio(false) ;cin.tie(NULL) ;}
void dbg(vector<ll> tab){for(auto it : tab) cout<<it<<" ";cout<<endl;}
void dbgg(pi p){cout<<p.F<<" "<<p.S<<endl;}
void dbgmp(map<ll,ll> mp){for(auto p: mp) cout<<p.F<<" "<<p.S<<endl;}
void dbgpi(vector<pi> tab){for(auto it : tab) dbgg(it) ;}

const ll N = 1e18+5 , MOD =1e9+7, Q =1e5+3 ;
vi primes;
 ll jj =0 ;
void solve (){
    ll n ,m ;
    cin >> n >> m; 
    char t [n][m];
    for (ll i=0 ;i<n ;i++ ){
        for (ll j = 0 ; j<m ; j++){
            cin >>t[i][j];
        }
    }
    for (ll i=0 ;i<(n+1)/2 ;i++ ){
        for (ll j = 0 ; j<m ; j++){
            swap(t[i][j],t[n-i-1][j]);
        }
    }
    for (ll i=0 ;i<n ;i++ ){
        for (ll j = 0 ; j<(m+1)/2 ; j++){
            swap(t[i][j],t[i][m-1-j]);
        }
    }
    cout << "Test " << ++jj <<endl;
    for (ll i=0 ;i<n ;i++ ){
        for (ll j = 0 ; j<m ; j++){
            cout << t[i][j];
        }
        cout <<endl;
    }
}

int main(){
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