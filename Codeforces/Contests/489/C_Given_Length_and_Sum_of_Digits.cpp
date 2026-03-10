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

map<string,vector<string>> graph;
map<string,int>vis;
vector <ll> v, vs ,pre, primes;
map <ll,ll> mp,par;
// set <ll> s;
ll x;

void solve()
{
    ll m , ss ; cin >> m >> ss; string mx="", mn=""; ll s= ss;
    if ( m==1 && s<10){cout << s << " "<< s <<endl; return;}
    if ( s==0 || s>m*9){ cout << -1 << ' '<< -1 << endl; return;}
    fr(i,0,m){
        char ch;
        if ( s> 9) {
            ch='9'; 
            s-=9;
        }
        else {
            ch=s+'0';
            s=0;
        }
        mx+=ch;
    }  
    s=ss;
    fr(i,1,m+1){
        char ch;
        if (i==m)ch=s+'0';
        else if ( s>10) {
            ch='9'; 
            s-=9;
        }
        else if (s>1){
            ch=s-1+'0';
            s=1;
        }
        else{
            ch='0';
        }
        mn+=ch;
    }
    reverse(mn.begin(),mn.end());
    cout << mn <<" "<<mx;
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
     // cin >> tt;
     while (tt--)
          solve() ;
}
