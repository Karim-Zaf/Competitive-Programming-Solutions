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

const ll N = 5e5 +4 , MOD =1e9+7, Q =1e5+3 ;

vi garph[N];

void solve(){
    ll x, q, y, n=-1 ;
    cin >> q;  
    vector < set<ll>  > tab(N);
    for (ll i=0 ;i<q ; i++) {
        cin >> x; 
        if ( x==1 ){
            cin >> x ;
            tab[x].insert(++n);
        }
        else {

            cin >> x >> y ;
            if (x!=y){
                if (tab[x].size()>tab[y].size() )
                   swap(tab[x],tab[y]);
                for (auto z : tab[x])
                    tab[y].insert(z);
                if (x!=y)
                    tab[x].clear() ;
            }
        }
    }
    vector <ll> v (n+1);
    ll i= 0 ;
    for (auto z : tab ) {
        for (auto e : z )
            v[e] = i; 
        i++;
    }
    dbg(v);
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
