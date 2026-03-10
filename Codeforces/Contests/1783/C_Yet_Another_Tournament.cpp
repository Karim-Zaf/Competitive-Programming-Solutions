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

void solve(){
    ll n , m; 
    cin >> n >> m ;
    vector <ll> vec (n), indexes(n), pref(n), a(n);
    for (ll i =0 ;i<n ; i++){
        cin >> a[i];
        vec[i]=a[i];
    }
    sort ( all(vec));
    pref[0]=vec[0];
    for (ll i=1 ;i<n ;i++)
        pref[i]=pref[i-1]+vec[i];
    ll pos = upper_bound(all(pref),m)-pref.begin();  
    if (pos == 0 && pref[0]>m){
        cout << n+1 <<endl;
        return;
    }  
    if ( pos == n){
        cout << 1 <<endl;
        return;
    }
    pos--;
    if ( pref[pos]-vec[pos]+a[pos+1]<=m)
        cout << n-pos-1 <<endl;
    else cout << n-pos << endl;
    
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