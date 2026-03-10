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
    ll n , m;
    string res="";
    cin >> n >> m;
    vi v ( n);
    for (ll i =0 ; i<n ; i++ )
        cin >> v[i];
    for (ll i=0 ;i< m ;i++)
        res += 'B';
    for (ll i =0 ; i<n ; i++ ){
        ll pos1 = m-v[i];
        ll pos2 = v[i]-1;
        // watch(pos1);
        // watch(pos2);
        if (pos1 <pos2 && res[pos1]=='B'|| res[pos2]=='A'){
            res[pos1]='A';
            // watch(pos1);
        }
        else {
            res [pos2]='A';
            // watch(pos2);
        }
    }
    

    cout << res <<endl;
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