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
void dbgpi(vector<pi> tab){for(auto it : tab) dbgg(it) ;}

const ll N = 1e6+3;

vector <ll> graph[N];
vector <ll> allez , retour;
bool vis[N];

void dfs1 ( ll parent){
    vis [parent]= 1;
    allez.pb(parent);
    for (auto child: graph[parent]){
        if (! vis[child]){
            dfs1(child);
            
        }
    }
}
void dfs2 ( ll parent){
    vis [parent]= 1;
    retour.pb(parent);
    for (auto child: graph[parent]){
        if (! vis[child]){
            dfs2(child);
            
        }
    }
}

void solve(){
    ll n ;
    cin >> n ;
    ll premier=0 , dernier=0, othera , otherb ;
    map<ll,ll>mp, mp2;
    for (ll i=0 ;i<n ; i++){
        ll a,  b ; 
        cin >> a >> b ;
        mp[b]++;mp[a]++;
        mp2[b]++;
        if ( !a ) {
            dernier = b ;
            continue;
        }
        if ( !b ) {
            premier = a ;
            continue;
        }   
        othera= a ;
        otherb =b ;
        
        graph[a].pb(b);
        graph[b].pb(a);
    }
    for (auto z : mp)
        if ( mp[z.F]==1 && n%2&& mp2[z.F])
            premier=z.F;

    if (premier==dernier){
        cout << othera << " "<< premier << " "<<otherb <<endl;
        return;
    }
    memset (vis,0, sizeof(vis));
    dfs1 ( premier ) ;
    memset (vis,0, sizeof(vis));
    dfs2 ( dernier );
    // dbg( retour);
    // dbg( allez);
    ll n1 = allez.size(), n2 = retour.size();
    ll i=n1-1 , j = 0;
    while (j<n2 || i>=0 ){
        if (i>=0 ){
            cout << allez[i]<< " ";
            i--;
        }
        if (j<n2){
            cout << retour[j]<< " ";
            j++;
        }
    }

}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("outputt.txt","w",stdout);
    #endif
    FAST ;
    io() ;
    srand(time(0)) ;
    ll tt=1;
    // cin >> tt;
    while (tt--)
        solve() ;
}