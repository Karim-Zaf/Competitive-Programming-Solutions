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

const ll N = 1e5+2 , MOD =1e9+7, Q =2e5+3 ;
 

void solve(){
    ll n, x ,a , b, res = INF , cnt = 0 ; 
    cin >> n ; 
    vi v(n) , pref(n+1);
    for (ll i=0 ; i<n ; i++ ){
        cin >> v[i] ; 
    }
    res = max ( v[0] , v[n-1]) - min (  v[0] , v[n-1]) ; 
    for (ll i=1 ; i<n ; i++ ){
        if (v[i]== v[n-i-1])continue;
        res = __gcd ( res , max ( v[i] , v[n-i-1]) - min (  v[i] , v[n-i-1]) )  ; 
    }

    // map<ll,ll> mp ;
    // for (ll i= 0;i<n ; i++ ){
    //     cin >> v[i] ; 
    //     mp[v[i]]++ ;
    //     pref[v[i]]++ ;   
    // }
    // for (ll i= n-1;i>=0 ; i-- )
    //     pref[i] += pref[i+1] ;
    // ll kadheba = pref[n] ; 
    // while ( kadheba>=1){
    //     if (pref[kadheba] == kadheba ){
    //         cout << kadheba <<endl; 
    //         return ;    
    //     }
    //     kadheba =  pref[n-kadheba] ; 
    // }

    cout << res <<endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; ll test_case=1;    
    cin >> test_case ;   
    while (test_case--)  solve() ;
}