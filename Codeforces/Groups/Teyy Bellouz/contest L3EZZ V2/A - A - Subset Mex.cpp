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

const ll N = 1e7+5 , MOD =1e9+7, Q =1e10+3 ;


void solve () { 
    ll n ; 
    cin >> n; 
    vi v(n) , mp(101 , 0 ) ; 
    for (ll i= 0 ;i<n ; i++ ){
        cin >> v[i] ;
        mp[v[i]]++ ;  
    }
    ll  mex1 = 0 , mex2 = 0 ; 
    if (mp[0]>=1) mex1 = 1; 
    if (mp[0]>=2) mex2 = 1; 
    for (ll i = 1 ;i<n ; i++ ) {
        if ( mp[i]>=1 && mex1 == i)
            mex1 ++ ; 
        if ( mp[i]>=2 && mex2 == i)
            mex2 ++ ; 
    }
    cout << mex1 + mex2 <<endl; 
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ;
    ll tt=1;  ;  
    cin >> tt ;   
    while (tt--)
        solve() ;
}