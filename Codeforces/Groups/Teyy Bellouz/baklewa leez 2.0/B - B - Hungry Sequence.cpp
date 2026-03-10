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

const ll N = 1e7 , MOD =1e9+7, Q =2e5+3 ;

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

void solve(){
    ll n ; 
    cin >> n; 
    for (ll i= 0 ;i<n ; i++)
        cout << primes[i] << " " ; 
    cout <<endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    primes = sieve (N);
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; ll test_case=1;    
    // cin >> test_case ;   
    while (test_case--)  solve() ;
}