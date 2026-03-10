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

const ll N = 1e5+7 , mod =1e9+7, Q =1e5+3 ;
ll fibn[100];

void solve(){
    ll n , res = 0 ; 
    cin >>n; 
    vi v(n), mp(n,0);
    for (ll i= 0 ; i<n ; i ++)
        cin >> v[i];
    sort (all(v));
    for (ll i=0 ; i<n-2 ; i++){
        for (ll j=i+1 ; j<n-1 ; j++){
            for (ll k=j+1 ; k<n ; k++){
                if ( v[i]+v[j] >v[k] && v[i]+v[k]>v[j] && v[k]+v[j]>v[i]
                    && !mp[i] && !mp[j]&&!mp[k]){
                    res++;
                    mp[i]++;
                    mp[j]++;
                    mp[k]++;
                }
            }
        }
    }

    cout << res <<endl;
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
