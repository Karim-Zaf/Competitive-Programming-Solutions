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
map <ll,ll> mp;
set <ll> ss;
ll x;
    
void solve(){
    ll n ;cin >>n ;
    if (!(n%2))
        cout << n/2 << " "<< n/2<< endl;
    else{
        ll a =0 ,b= 0 ; ll doura=0, j=1;
        while ( n){
            if ((n%10)%2 && doura%2){
                a+=((n%10)/2)*j;
                b+=((n%10)-(n%10)/2)*j;
                doura++;
            }
            else if ((n%10)%2){
                b+=((n%10)/2)*j;
                a+=((n%10)-(n%10)/2)*j;
                doura++;
            }
            else{
                b+=((n%10)/2)*j;
                a+=((n%10)/2)*j;
            }
            j*=10;
            n/=10;
            
        }
        cout << a<< " "<<b<<endl;
    }

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