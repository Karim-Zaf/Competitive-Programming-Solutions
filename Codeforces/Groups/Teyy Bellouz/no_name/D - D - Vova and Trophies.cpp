//  (1/0+) WINS
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
#define pb push_back
#define pi pair<ll,ll>
#define vi vector<ll>
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define MOD mod
#define INF (ll)(1e18)
void dbg(vector<ll> tab){for(auto it : tab) cout<<it<<" ";cout<<endl;}
void dbgmp(map<ll,ll> mp){for(auto p: mp) cout<<p.F<<" "<<p.S<<endl;} 
void dbgg(pi p){cout<<p.F<<" "<<p.S<<endl;}
void dbgpi(vector<pi> tab){for(auto it : tab) dbgg(it) ;}

const ll N = 2e5+5 , MOD = 998244353, Q =2e5+3 ;


void solve(){
    ll n , i = 0 , nbG = 0 ,res = 0  ; 
    string ch ; 
    cin >> n >> ch ; 
    vi kodem (n ) , lteli (n )  ;
    kodem[0] = (ch[0]=='G'? 1:0) ; 
    lteli[n-1] = (ch[n-1]=='G'? 1:0) ; 
    for (auto z  : ch )   nbG += ( z =='G'? 1 : 0) ; 
    for ( ll i =   1 ; i<n ;i ++){
        if (ch[i]=='S')continue;
        kodem[i] = kodem[i-1] +1 ;
        res = max ( res , kodem[i]) ; 
    }
    for ( ll i = n-2 ; i>=0 ;i --){
        if (ch[i]=='S')continue;
        lteli[i] = lteli[i+1] +1 ;
        res = max ( res , lteli[i]) ; 
    }

    if ( ch[n-1]=='S' && nbG > kodem[n-2]){ res = max (res , kodem[n-1]+1);}
    if ( ch[0]=='S' && nbG > lteli[1]){ res = max (res , lteli[1]+1);}
    for (ll i= 1 ;i<n-1 ; i++){
        if (ch[i]=='S'){
            if (nbG > kodem[i-1] +lteli[i+1]){
                res = max (res , kodem[i-1]+lteli[i+1]+1);
            }
            res = max ( res , kodem[i-1]+ lteli[i+1]);
            if (nbG> kodem[i-1]){ res = max (res , kodem[i-1]+1);}
            if (nbG> lteli [i+1]) { res = max ( res , lteli[i+1]+1);}
            // watch (nbG> kodem)
        }
    }
    cout << res <<endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ;
    ll tt=1;  ;   
    // cin >> tt ;   
    while (tt--)
        solve() ;
}