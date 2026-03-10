//  (1/0+) WINS
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
#define pb push_back
#define pi pair<ll,ll>
#define vi vector<ll>
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define MOD mod
#define INF (ll)(1e18)
void dbg(vector<ll> tab){for(auto it : tab) cout<<it<<" ";cout<<endl;}
void dbgmp(map<ll,ll> mp){for(auto p: mp) cout<<p.F<<" "<<p.S<<endl;} 
void dbgg(pi p){cout<<p.F<<" "<<p.S<<endl;}
void dbgpi(vector<pi> tab){for(auto it : tab) dbgg(it) ;}

const ll N = 1e7+5 , MOD =1e9+7, Q =1e10+3 ;
vi primes ; 

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

vi factors(int n){
    vi res;
    for(int i = 0; i < primes.size() && primes[i]*primes[i] <= n;i++){
        if(n % primes[i] == 0)res.pb(primes[i]);
        while(n % primes[i] == 0){
            n /= primes[i];
        }
    }
    if(n > 1)res.pb(n);
    return res;
}

void solve () { 
    ll n , res = 0 , zyed = 0,x  ; 
    cin >> n; 
    vi v( n) ; 
    map <ll,ll> mp ; 
    for (ll i=0 ; i< n; i++ ){
        cin >> x ; 
        for(int i = 0; i < primes.size() && primes[i]*primes[i] <= x;i++){
            while(x % primes[i] == 0){
                mp[primes[i]]++ ;
               x /= primes[i];
            }
        }
        if(x > 1)mp[x]++;
    } 
    for (auto z : mp ){
        res += z.S /2 ; 
        zyed += z.S %2 ; 
    }
    cout << res + zyed /3 <<endl; 
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ;
    ll tt=1;  
    primes = sieve (N ) ;  
    cin >> tt ;   
    while (tt--)
        solve() ;
}