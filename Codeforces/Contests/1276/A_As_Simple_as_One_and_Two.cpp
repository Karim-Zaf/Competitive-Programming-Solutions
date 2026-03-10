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
 
const ll N = 1e5+3, mod= 1e9 +7;
 
vector <ll> vv, primes;
// map <ll,ll> mp;
set <ll> ss;
ll x;
    
void solve(){
    string x ;
    vv.clear();
    cin >> x;
    ll n = x.size();
    fr(i,0,n-2){
        if (x[i]=='t' && x[i+1]=='w'&& x[i+2]=='o' || x[i]=='o' && x[i+1]=='n'&& x[i+2]=='e' ){
            if (x[i]=='t' && x[i+1]=='w'&& x[i+2]=='o' && x[i+3]=='n'&&x[i+4]=='e'&& i<n-4 ){
                    vv.pb(i+3);
                    x[i+2]='j';
                }
                else vv.pb(i+2);
        }
    }
    cout << vv.size()<<endl;
    dbg(vv);
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
     cin >> tt;
     while (tt--)
          solve() ;
}