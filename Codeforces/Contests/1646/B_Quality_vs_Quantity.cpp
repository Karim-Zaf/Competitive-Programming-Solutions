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

vector <ll> graph[N];
vector <ll> allez , retour;
bool vis[N];

void solve(){
    ll n , sum1=0 , sum2=0, sum=0 ; 
    cin >> n ;
    vi v (n);
    for (ll i=0 ;i<n ; i++)  { cin >> v[i];sum+=v[i];}
    sort (all(v));
    sum1=v[0] ;
    for (ll i =1 ;i<(n%2 ? n/2 +1 : n / 2) ; i++){
        sum1 += v[i];
        sum2 += v[n-i];
        if (sum2 > sum1 ){
            yes
            return; 
        }
    }
    // dbg ( v);
    // watch (sum1);
    // watch(sum2);
    if (sum2>sum1)yes
        else no 
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("outputt.txt","w",stdout);
    #endif
    FAST ;
    io() ;
    srand(time(0)) ;
    ll tt=1;
    cin >> tt;
    while (tt--)
        solve() ;
}