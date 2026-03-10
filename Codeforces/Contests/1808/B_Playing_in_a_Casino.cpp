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
void dbgmp(map<ll,ll> mp){for(auto p: mp) cout<<p.F<<" "<<p.S<<endl;}
void dbgpi(vector<pi> tab){for(auto it : tab) dbgg(it) ;}

const ll N = 1e6+7 , mod =1e9+7, Q =1e5+3 ;
vi graph[N];
vi vis ( N,0), t(N,-1);
ll depth=0, mx=0;


void solve(){
    ll n ,m , x , cnt =0; 
    cin >> n >> m;
    ll t[n][m];
    for (ll i=0 ;i<n ; i++){
        for (ll j =0 ; j<m  ; j++){
            cin >> t[i][j] ;
        }
    
    }
    for (ll j =0 ; j<m  ; j++){
        priority_queue<ll> p;
        for (ll i=0 ;i<n ;i++){
            p.push(t[i][j]);
        }
        for (ll i=0 ;i<n ;i++){
            ll x = p.top();
            cnt += x * ( n-1-i) - x*(i); 
            p.pop(); 
        }   
    }
    cout << cnt <<endl;
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
