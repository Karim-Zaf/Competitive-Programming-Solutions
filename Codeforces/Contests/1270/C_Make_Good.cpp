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
    ll n , xr, x,  sum;
    cin >> n >> x ;
    sum=x; 
    xr = x;
    for ( ll i =1 ; i<n ; i++){
        cin>> x ;
        sum+=x;
        xr^=x;
    }
    // if (2*xr==sum)
    //     cout <<0 <<endl<<endl;
    // else if (!( 2*xr>=sum))
        cout << 2 <<endl << xr << " "<< sum+xr <<endl;
    // else
    //     cout << 2 <<endl << (2*xr-sum)/2 << " "<<(2*xr-sum)/2<<endl;

    // watch(xr);
    // watch(sum);
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