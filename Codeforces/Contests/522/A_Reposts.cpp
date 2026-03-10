#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
#define FAST ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define pb push_back
#define pi pair<ll,ll>
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define fr(i,a,b) for(ll i = a;i < (ll)b;i++)
#define rfr(i,a,b) for(ll i = a;i > (ll)b;i--)
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define INF (ll)(1e18)
void io(){ios::sync_with_stdio(false) ;cin.tie(NULL) ;}
void dbg(vector<string> tab){for(auto it : tab) cout<<it<<" ";cout<<endl;}
void dbgg(pi p){cout<<p.F<<" "<<p.S<<endl;}
void dbgpi(vector<pi> tab){for(auto it : tab) dbgg(it) ;}

const ll N = 202;

map<string,vector<string>> graph;
map<string,int>vis;
vector <ll> v;
map <ll,ll> mp;
set <ll> s;
int res=2,mx=0;

// void dfs(string par){
//      for (auto child: graph[par]){
//           if (graph[child].empty()){
//                mx=max(mx,res);
//                res=2;
//                return;
//           }
//           res++;
//           dfs(child);
//      }
// }
void solve()
{
     int n ; cin >> n;
     for ( int i =0 ; i <n ; i++){
          string a, b,c ; cin >> a >> b>> c;
          transform(a.begin(), a.end(), a.begin(), ::tolower);
          transform(c.begin(), c.end(), c.begin(), ::tolower);
          
          vis[a]=vis[c]+1;
          mx=max(vis[a],mx);
     }
     // for (auto x: graph){
     //      cout << x.F << "  ";
     //      dbg(x.S);
     // }
     // dfs("polycarp");
     cout << mx+1<< endl;
     
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout); 
    #endif 
    FAST ;
    io() ;
    srand(time(0)) ;
     ll tt=1;
     //  cin >> tt;
    while (tt--)
        solve() ;
}



