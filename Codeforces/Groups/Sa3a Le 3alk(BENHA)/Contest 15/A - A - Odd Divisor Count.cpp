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

const ll N = 1e5+7 , MOD =1e9+7, Q =1e5+3 ;

void solve(){
    ll res= 0 ,a,b , n ; 
    string v ;
    cin >> a >> b ;  
    for (ll i=1; i<=100 ; i++){
        if ( a<=i*i && i*i<=b)res++;
    }
    // for (ll i=0 ;i<)
    // for (ll i= 0 ;i<v.size()-2 ; i++){
    //     if ( 
    //     v[i]!='e' &&  v[i]!='i' && v[i]!='o' && v[i]!='a' && v[i]!='u'&&
    //     v[i+1]!='e' &&  v[i+1]!='i' && v[i+1]!='o' && v[i+1]!='a' && v[i+1]!='u'&&
    //      v[i+2]!='e' &&  v[i+2]!='i' && v[i+2]!='o' && v[i+2]!='a' && v[i+2]!='u'){
    //         no return; 
    //     }
    // }

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
