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

const ll N = 1e4+5 , MOD =1e9+7, Q =1e5+3 ;
// 0011001000
// 0000111110
// 0000010111
void solve (){
    ll n, x , k,  res = 0, i =  0  , ekher_sfer = -1 , hachtna =-1 ; 
    string ch ;
    cin >> n >> k >> ch ;
    while ( res < k && i<n ) {
        if ( ch[i]=='0'){
            if (k-res>=i -ekher_sfer-1 ); 
            else    hachtna = i-k+res;  
            res+= i - ekher_sfer - 1 ;
            ekher_sfer ++ ; 
        }
        i++; 
    }
    for (ll j= 0 ;j< i; j++)ch[j]='1'; 
    if (res<=k)
        for (ll i= 0 ;i< ekher_sfer+1; i++)ch[i]='0';
    else{ 
        for (ll i= 0 ;i< ekher_sfer; i++)ch[i]='0'; 
        if (hachtna!=-1) ch[hachtna]='0';
    }
    cout << ch <<endl;
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