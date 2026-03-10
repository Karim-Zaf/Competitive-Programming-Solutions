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

const ll N = 1e7 +5 , MOD =1e9+7, Q =1e5+3 ;

void solve(){
    ll n , a , b ,q, k, x , res = 0, i=0;
    cin >> n >> q ; 
    vi v (n ) , pref(n+1); 
    for (ll i = 1 ; i<=n ; i++)
        cin >> v[i];
    for (ll i = 1 ; i<=n ; i++)
        pref[i]= pref[i-1]+v[i];
    while ( q--) {
        cin >> x; 
        ll aana = -1 ; 
        for (ll i= n ; i>=0 ; i--){
            ll lawej = pref[i]-x ;
            ll pos = lower_bound (all(pref), lawej) -pref.begin() ;
            if (pref[pos]==lawej && aana == -1){
                a= pos , b = i-1 ; 
                aana = b-a+1;
            }
            else if ( pref[pos]==lawej  && aana>=(i-pos)){
                a= pos , b = i-1 ; 
                aana = b-a+1;
            }
        }
        cout << a << " "<<b <<endl;
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
    // cin >> tt;
    while (tt--)
        solve() ;
}