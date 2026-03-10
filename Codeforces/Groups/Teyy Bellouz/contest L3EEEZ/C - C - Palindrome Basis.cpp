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

const ll N = 1e5 , mod =1e9+7, Q =1e5+3 ;

ll dp[N];
set <ll> palind ; 

bool palindrome (ll a ){

    if (a>=0 && a<=9)
        return 1;
    if ( a>=10 && a<=99 && (a%10)==(a/10))
        return 1;
    else if ( a>=100 &&a<=999 && a%10==a/100)
        return 1;
    else if ( a>=1000 &&a<=9999 && a%10==a/1000 &&((a/10)%10)==(a/100)%10 )
        return 1;
    else if ( a>=10000 &&a<=99999 && a%10==a/10000 &&((a/10)%10)==(a/1000)%10 )
        return 1;
    return 0;
}
void solve(){
   ll n ; 
   cin >> n ;
   cout << dp[n] <<endl;
    
}

void preprocess(){
    // memset( dp , 0 , sizeof(dp));
   dp[0]=1;
   for (ll i=1 ; i<N-1 ; i++ )
        if ( palindrome (i))
            palind.insert(i);
    for (auto  x: palind){
        for (ll i=1 ; i<N-1 ; i++ ){
            if ( i>=x) 
                 dp[i]= ((dp[i] + dp[i-x])%mod + mod)%mod;
        }
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
    preprocess();
    cin >> tt;
    while (tt--)
        solve() ;
}
