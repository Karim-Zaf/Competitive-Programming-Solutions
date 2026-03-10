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
vi graph [N];
ll vis [N];
set<ll> sol[N];

void solve(){
    ll mx=0 ,n ;
    cin >> n ;
    map <ll,ll> mp;
    vi v (n+1), ans (n+1,0);
    for (ll i=1 ;i<=n ;i++){
        cin >> v[i];
        v[i];
        mx= max ( mx , v[i]);
    }
    for (ll i=1; i<=n; i++){
        if (mp[v[i]]){
            ll dis = i-mp[v[i]]-1;
            if ( dis %2 ==0){
                ans[v[i]]++;
                // watch(v[i]);
                // watch(i);
            }
            else continue;
        }
        else ans[v[i]]++;
        mp[v[i]]=i;
    }
    for (ll i=1; i<=n; i++)
        cout << ans[i] << " ";cout <<endl;
    // dbg (ans);
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("outputt.txt","w",stdout);
    #endif
    FAST ;
    io() ;
    srand(time(0)) ;
    ll tt=1;
    cin >> tt;
    while (tt--)
        solve() ;
}