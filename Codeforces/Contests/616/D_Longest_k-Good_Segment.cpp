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
 
const ll N = 1e6+5 , MOD =1e9+7, Q =2e5+3 ;
 
void solve(){
    ll n , k , res , nb_diff=0, j=0 , l_res= 0 , r_res  , l   ; 
    cin >> n >> k ; 
    vi v(n) , mp(N) ; 
    for (ll i= 0 ;i<n ; i++) 
        cin >> v[i]  ; 
    while ( nb_diff <k  && j<n ){
        if (!mp[v[j]])nb_diff++;
        mp[v[j++]]++ ;
    }
    l_res = 0 , r_res = j-1 , l = 0 ; 
    for (ll r = j ;r<n ; r++){
        if (mp[v[r]]) mp[v[r]]++ ; 
        else { mp[v[r]]++ ; nb_diff++ ;}
        while (nb_diff > k && l<r){
            mp[v[l]]-- ; 
            if ( !mp[v[l]])nb_diff -- ; 
            l++ ; 
        }
        if ( abs(r-l)> abs(r_res - l_res)){ r_res = r ; l_res = l ; }
    }
    cout << ++l_res << " " << ++r_res <<endl;
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