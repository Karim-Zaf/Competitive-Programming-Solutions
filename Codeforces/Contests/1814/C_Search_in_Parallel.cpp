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
    ll n, x ,s1, s2 ,res = 0, g=1, aaa =1 ,bbb =1; 
    cin >> n >>s1 >> s2 ; 
    vector<pair <ll,ll>>  v;
    vi a, b  ; 
    for (ll i=1 ;i<=n ; i++ ){
        cin >> x ; 
        v.pb({x,i});
    }
    sort(rall(v));
    for (ll i = 0 ;i<n ;i++ ){
        if (aaa*v[i].F*s1==bbb*v[i].F*s2){
            if (s1<s2){
                aaa++; 
                a.pb(v[i].S);
            }
            else {
                bbb++; 
                b.pb(v[i].S);
            }
        }
        else if ( aaa*v[i].F*s1>bbb*v[i].F*s2){
            b.pb(v[i].S);
            bbb++;
        }
        else {
            aaa++;
            a.pb(v[i].S);
        }
    }
    cout << a.size()<< " ";
    dbg(a);
    cout << b.size()<< " ";
    dbg(b);
    // vi v (100,0);
    // // cout << (1ll<<32) <<endl;
    // ll step =abs(n-x);
    // ll a=0 , b=0; 
    // while ((a+b-step)%2 || a+b<step ){
    //     b++;
    //     a+= b;
    // }
    // cout << a <<endl;
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
