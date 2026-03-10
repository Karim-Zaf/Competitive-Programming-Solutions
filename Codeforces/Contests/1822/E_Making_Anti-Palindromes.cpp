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

const ll N = 2e5+5 , MOD =1e9+7, Q =2e5+3 ;

void solve(){
    ll n , cnt  = 0 ; 
    string ch ; 
    cin >> n >> ch; 
    map <char ,ll> mp ; 
    for (auto z : ch){
        mp[z]++;
        if ( mp[z]>n/2 || n%2) {cout <<-1 <<endl; return; }
    }
    mp.clear();
    for (ll i= 0  ; i<n/2 ; i++){
        if ( ch[i] == ch[n-i-1]) {cnt ++ ;mp[ch[i]]++ ;} 
    }
    for (auto x : mp )
        if ( x.S> cnt/2){cout << x.S <<endl; return;}
    cout << cnt/2 + cnt%2 <<endl; 
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