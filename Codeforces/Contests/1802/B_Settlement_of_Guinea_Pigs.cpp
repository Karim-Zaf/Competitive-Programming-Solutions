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
    ll n, cnt =0,res=0, alone=0 , empty =0 ;
    cin >> n;
    vi v( n ); 
    for (ll i=0 ;i<n ; i++){
        cin >> v[i];
    }
    for (ll i =0 ; i<n ; i++){
        if (v[i]==1 && i<n-1){
            cnt ++;
        }
        else if (v[i]==1 && i==n-1) {
            cnt++;
            res+= cnt - min(cnt,empty);
            empty -= min(cnt,empty);

        }
        else if ( cnt){
            res+= cnt - min(cnt,empty);
            empty -= min(cnt,empty);
            if ( cnt %2  && alone>=2) {
                empty++;
                alone --;
            }
            else if ( cnt%2==0 && alone>=1)
                empty++;
            else if  (cnt%2) alone++;
            else alone+=2;
            empty+=cnt/2 - (cnt%2 ? 0:1);
            cnt =0 ;
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