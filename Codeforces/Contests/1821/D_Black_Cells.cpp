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

const ll N = 1e5+2 , MOD =1e9+7, Q =2e5+3 ;
 

void solve(){
    ll n , k , sum = 0 , res = 2e9; 
    cin >> n >> k ; 
    priority_queue <ll , vector <ll>, greater<ll>> pq;
    vi l (n) , r(n) ; 
    for (ll i= 0 ;i<n ; i++ ) cin >> l[i];
    for (ll i= 0 ;i<n ; i++ ) cin >> r[i];

    for (ll i= 0 ;i<n ; i++){
        ll len = r[i]-l[i]+1 ; 
        sum += len  ; 
        pq.push (len ) ; 
        while ( sum - pq.top() >= k){
            ll zeyed = sum - k ; 
            ll curr = r[i]  - zeyed ;
            ll hesba = curr     + 2 * pq.size() ;  
            res= min ( res , hesba) ; 
            sum -= pq.top(); 
            pq.pop () ; 
        }
        if (sum >= k ){
            ll zeyed = sum - k ; 
            ll hesba = r[i] -zeyed + 2 * pq.size() ;  
            res= min ( res , hesba ) ; 
        }
    }
    cout << (res==2e9 ? -1 : res)  <<endl ; 
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; ll test_case=1;    
    cin >> test_case ;   
    while (test_case--)  solve() ;
}