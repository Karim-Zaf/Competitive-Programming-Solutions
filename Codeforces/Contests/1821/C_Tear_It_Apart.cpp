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

const ll N = 2e5+5 , MOD =1e9+7, Q =1e5+3 ;

void solve () {
    string ch ; 
    cin >> ch ; 
    ll n = ch .size() , res=-1 ;
    for (char c = 'a'  ; c <= 'z' ; c++ ){
        ll i= 0 , hesba=0 , overall = 0  , mini_res = -INF ;
        // watch(c)
        while (i<n ) {
            ll cnt = 0 ;
            if ( ch[i]==c){i++ ;continue; }
            while ( ch[i]!=c && i<n ) {overall ++ ; cnt ++ ; i++ ;}
            // watch(cnt ) ; 
            hesba = 0 ; 
            while(cnt >0){
                hesba++ ; 
                cnt/=2; 
            } 
            // watch(hesba) ; 
            mini_res = max (hesba, mini_res ) ; 
        }
        if (!overall) {res = 0 ;continue; }
        if ( c== 'a' ) res = mini_res ;  
        else res = min ( mini_res , res); 
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
    cin >> tt;
    while (tt--)
        solve() ;
}