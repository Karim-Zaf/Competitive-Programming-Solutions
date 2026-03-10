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
#define watch(x) cout << "\n" << (#x) << " is " << (x) << endl
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
 
const ll N = 1e6+3, mod= 1e9 +7,N_max = 1<< 17 +5;
vi primes;
ll x, n, val, p  ;
ll tree [4*N_max];

vi sieve ( ){
    vi v ( N ,0),    prime ; 
    for ( ll i = 2 ; i <= N; i++){
        if ( ! v[i]){
            prime.pb(i);
            for(ll j=i; j<= N;j+=i){
                v[j]=1;
            }
        }
    }
    return prime;
}

void solve(){
    ll n ,l, nyassine =1e9 , nrami=1e9 ;
    map <ll , ll > a,b ; 
    cin >>n >> l;
    for ( ll i = 0 ; i< n ; i++){
        cin >> x;
        for ( ll j=0 ; primes[j]<=l && primes[j]*primes[j]<=x ; j++){
            ll factor = primes[j];
            while (!( x%factor)){
                a[ factor]++;
                x/=factor;
            }
        }
        if (x>1) a[x]++;
    }
    for ( ll i = 0 ; i< n ; i++)  {
        cin >> x;
        for ( ll j=0 ; j < primes.size() && primes[j]*primes[j]<=x ; j++){
            ll factor = primes[j];
            // watch(factor);
            while (!( x%factor)){
                b[ factor]++;
                x/=factor;
            }

        }
        if (x>1) b[x]++;
    }
    for ( ll j=0 ; primes[j]<=l; j++){
        nrami =min (nrami , a[primes[j]]);
        nyassine=min (nyassine, b[primes[j]]);
    }

    // watch(nyassine);
    // watch(nrami);
    if ( nrami >= nyassine)
        cout << "Rami" <<endl;
    else 
        cout <<  "Yessine" <<endl;

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
     primes = sieve();
     // cin >> tt;
     while (tt--)
          solve() ;
}