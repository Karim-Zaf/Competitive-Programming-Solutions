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
 
vi graph[N] ; 
ll vis[N]; 
set<ll> s , mchmwjoudin ; set<set<ll>> ans ; 
void dfs ( ll parent){
    s.insert(parent);
    vis [parent]= 1;
    for (auto child: graph[parent]){
        if (! vis[child]){
            dfs(child);
        }
    }
}

void solve(){ 

    ll n , k ; 
    cin >> n >> k ; 
    for (ll i= 0 ;i<k ; i++) {
        ll a , b ; 
        cin >> a >> b; 
        graph[a].pb(b);
        graph[b].pb(a);
    }
    for (ll i = 1 ;i<=n ; i++ )mchmwjoudin.insert(i);

    for (ll i = 1 ;i<=n ; i++ ){
        memset(vis ,0 , sizeof(vis)); 
        s.clear() ;
        dfs(i) ; 
        if ( s.size()==3 || s.size()==2  ){
            ans .insert(s) ; 
            for (auto j : s ) mchmwjoudin.erase(j);
        }
        else if ( s.size()!=1) {cout << -1 <<endl; return;}

    }
    set <set<ll>> fin ; 
    for (auto x : ans ){
        if ( x.size() <3){
            set<ll> kdim  = x; 
            if (mchmwjoudin.empty()){cout << -1 << endl; return ; }
            x.insert(*mchmwjoudin.begin());
            // watch (1);for (auto z : x ) cout <<  z << " "; cout<<endl;
            mchmwjoudin.erase (*mchmwjoudin.begin());
        }
        fin .insert(x);
    }
    if (mchmwjoudin.size()%3){cout << -1 <<endl; return;}
    for (auto x : fin ){
        for (auto z : x){
            cout << z << " "; 
        }   
            cout <<endl;
    }
    ll i= 1 ;  
    for (auto j : mchmwjoudin){
        cout<< j << " "; 
        if(i%3==0)cout <<endl;
        i++;
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; ll test_case=1;    
    // cin >> test_case ;   
    while (test_case--)  solve() ;
}