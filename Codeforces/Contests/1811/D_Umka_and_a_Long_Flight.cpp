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
    ll n , x , y  ; 
    cin >> n >> x >> y ; 
    for (ll i = n; i>1 ; i--){
        ll form = fibn[i+1]+2-(y+1);
        ll diff = fibn[i+1]-fibn[i];
        ll jdid = form ; 
        // watch(jdid )
        // watch(diff)
        if ( y<jdid)
            jdid =y ;
        if (jdid > diff){
            no 
            return; 
        }
        if ( y>form)
            y =form ;
        ll comp = x; 
        x = y ; 
        y = comp;
    }
    yes

}

int main(){

    fibn[0]=1;
    fibn[1]=1;
    for (ll i=2 ;i<100 ; i++)
        fibn[i]=fibn[i-1]+fibn[i-2];

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
