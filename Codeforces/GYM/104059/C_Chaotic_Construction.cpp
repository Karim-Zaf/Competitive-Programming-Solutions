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
void dbgmp(map<string,ll> mp){for(auto p: mp) cout<<p.F<<" "<<p.S<<endl;}
void dbgpi(vector<pi> tab){for(auto it : tab) dbgg(it) ;}

const ll N = 1e18+5, mod =1e9+7, Q =1e5+3 ;

void solve(){
    ll n , q ; 
    set<ll> s ;
    cin >> n >> q ;
    vi vis (n,1); 
    while ( q--){
        char c ; 
        cin >> c ;
        if ( c == '?'){
            ll a , b ,z; 
            cin >>a >> z ; 
            b= max( a,z);
            a=min(a,z);
            if ( s.find(a)!=s.end()||s.find(b)!=s.end()){
                cout << "impossible"<<endl;
                continue;
            }
            s.insert(a);
            s.insert(b);
            auto iterator= s.end();
            iterator--;
            // for(auto x :s) cout << x << " "; cout <<endl;
            auto p1 = s.find(a) ;
            auto p2 = s.find(b) ;
            p1++;
            if ( *s.begin()== a && *iterator ==b || p1==p2)
                cout << "possible"<<endl;
            else 
                cout << "impossible"<<endl;
            s.erase(a);
            s.erase(b);
        }
        else if (c=='-'){
            ll x ; cin >> x ;
            s.insert(x);
        }
        else{
            ll x; cin >> x ;
            s.erase(x);
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
    // cin >> tt;
    while (tt--)
        solve() ;
}