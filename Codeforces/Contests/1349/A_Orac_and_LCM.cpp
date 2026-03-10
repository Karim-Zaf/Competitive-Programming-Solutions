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
#define watch(x) cout << (#x) << " is " << (x) << endl;
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

const ll N = 2e5 +5 , MOD =1e9+7, Q =1e5+3 ;

vi garph[N], primes;

vector <ll> sieve(int n ){
    vi vs(n+1,0), pri ;
    for  (int i =2 ; i<=n ; i++){
        if (!vs[i]){
            pri.pb ( i);
            for ( int j=i ; j<=n ; j+=i)
                vs[j]=1;
        }
    }
    return pri ;
}

void solve(){
    ll n, x , res = 1, g; 
    cin >> n; 
    vi v (n) , occ (N,0) ; 
    for (ll i= 0;i<n ;i ++){
        cin >> x;
        for (ll j=0 ;primes[j]*primes[j]<N ;j++){
            if (x%primes[j]==0){
                ll kadech = 1; 
                while (x%primes[j]==0){
                    x/=primes[j];
                    kadech*= primes[j];
                    occ [kadech]++;
                }
            }
        }
        if (x>1)occ[x]++;
    }
    for  (int i =0 ; i<primes.size() ; i++){
        ll j= primes[i], hachtna =1;
        while ( j<N && occ[j]>=n-1){
            hachtna = j ;
            j*=primes[i];
        }
        res*=hachtna ; 
    }
    cout << res <<endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    FAST ;
    io() ;
    srand(time(0)) ;
    ll tt=1;
    // cin >> tt;
    primes =sieve(N) ;
    while (tt--)
        solve() ;
}