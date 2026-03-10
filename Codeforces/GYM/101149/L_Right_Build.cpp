#include<bits/stdc++.h>

using namespace std;

//mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());
//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")
//typedef __int128 lll;

#define ll long long
#define ld long double
#define watch(x) cout << (#x) << " is " << (x) << endl
#define PI 3.1415926535897932384626433832795
#define EULER 2.7182818284590452353602874713
#define F first
#define S second
#define pb push_back
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define sz(x) (int((x).size()))

const ll mod = 1e9 + 7;
const ll INF = 1e9 ;
const ll MIN = -1e18 ;
const ll MAXII = 200005 ;

template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template<typename T> T lcm(T a, T b){return(a*(b/gcd(a,b)));}


string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i*i<=a;++i) if (a%i==0) return 0; return 1; }
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
void dbg(vector<ll> v){for (auto x : v) cout << x << " "; cout << endl;}
void dbgg(pair<ll, ll> p){cout << p.F << " " << p.S << endl;}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

vector<ll> adj[MAXII];
vector<ll> rev[MAXII];
ll tab[MAXII][3];
ll vis_glob[MAXII];
bool visited[MAXII];
bool processed[MAXII];
ll tailles[MAXII];
vector<ll> path;


void solve() {
    ll n,m,a,b; cin>>n>>m>>a>>b;
    for (int i=0; i<m ; i++){
        ll x,y; cin>>x>>y;
        adj[x].pb(y);
        rev[y].pb(x);
    }

    for (int i=0; i<=1; i++){
        for (int j=0; j<=n ; j++){
            tab[j][i] = INF;
        }
    }

    queue<ll> q;
    tab[a][0] = 0;
    q.push(a);
    while (!q.empty()){

        ll now = q.front(); q.pop();
//        visited[now] = 1;
        for (auto y: rev[now]){
            if (tab[y][0] > (tab[now][0]+1)){
                tab[y][0] = tab[now][0]+1;
                q.push(y);
            }
        }
    }
    tab[b][1]=0;
    q.push(b);
    while (!q.empty()){

        ll now = q.front(); q.pop();
//        visited[now] = 1;
        for (auto y: rev[now]){
            if (tab[y][1] > (tab[now][1]+1)){
                tab[y][1] = tab[now][1]+1;
                q.push(y);
            }
        }
    }

//    for (int j=0; j<=n ;j++){
//        watch(j);
//        for (int i=0; i<=1 ; i++){
//            watch(tab[j][i]);
//        }
//    }

    ll minii = INF;
    ll deb =0;
    ll ans = INF;
    for (int i=0; i<=n ; i++){
        if (tab[i][0]==INF || tab[i][1]==INF)
            continue;
        ll curr = tab[i][0] + tab[i][1];
        if (curr<ans){
            ans = curr;
            deb = i;
        }
    }
//    watch(ans);
//    watch(deb);

    for (int i=0; i<=n ;i++){
        tailles[i] = INF;
    }
    tailles[0]=0;
    q.push(0);
    while (!q.empty()){

        ll now = q.front(); q.pop();
        for (auto y: adj[now]){
            if (tailles[y] > (tailles[now]+1)){
                tailles[y] = tailles[now]+1;
                q.push(y);
            }
        }
    }
    ans = INF;
    for (int i = 0; i <= n; i++){
        if (tab[i][0] == INF || tab[i][1] == INF) continue;
        ll curr = tailles[i] + tab[i][0] + tab[i][1];
        ans = min(ans, curr);
    }
    assert(ans < INF);
    cout<<ans << endl;


}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int tc=1;
//    cin >> tc;
    while(tc--) {
        solve();
    }
}
