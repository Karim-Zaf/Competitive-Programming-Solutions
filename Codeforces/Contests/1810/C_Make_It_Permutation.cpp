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
void dbgmp(map<ll,ll> mp){for(auto p: mp) cout<<p.F<<" "<<p.S<<endl;}
void dbgpi(vector<pi> tab){for(auto it : tab) dbgg(it) ;}

const ll N = 1e9+7 , mod =1e9+7, Q =1e5+3 ;


void solve(){
    ll n ,x, c , d, cost=0, res = INF, cnt=0; 
    cin >> n >> c >> d ; 
    vi v  ;
    map<ll,ll> mp ;
    for (ll i=0 ;i<n ; i++){
        cin >> x;
        if ( mp[x] >=1)
            cost += c ; 
        else v.pb(x);
        mp[x]++;
    }
    sort(all(v));
    n= v.size() ;
    if (v[0]!=1){
        cost+= d ;
        v.pb(1);
        sort(all(v));
        res =n*c+cost;
        n++;
    }
    for (ll i=1;i<n ; i ++ ){
        res = min ( res , cost+ (n-i)*c );
        if(v[i]==i+1+cnt)continue;
        cost+= (v[i]-v[i-1]-1)*d ;
        cnt+=v[i]-v[i-1]-1 ;
    }

    cout << min (cost,res) <<endl;

    
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
