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

const ll N = 1e9+3;


void solve(){
    ll n , k , sum=0;
    cin >> n >> k;
    vi mod(k,0), a(n);
    for ( ll i=0 ;i<n  ; i++){
        cin >> a[i];
        mod [a[i]%k]++;
        sum+=(a[i]-a[i]%k);
    }
    sum/=k;
    ll lef = 1 , righ= k-1;
    while ( lef<=righ){
        if ( mod[lef]<=0){
            lef++;
            continue;
        }
        if ( mod[righ]<=0){
            righ--;
            continue;
        }
        if ( lef+righ>=k && lef!=righ|| lef+righ>=k && lef==righ &&  mod[lef]>=2 ){
            sum++;
            mod[lef]--;
            mod[righ]--;
        }
        else lef++;
        
    }
    cout << sum <<endl;
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