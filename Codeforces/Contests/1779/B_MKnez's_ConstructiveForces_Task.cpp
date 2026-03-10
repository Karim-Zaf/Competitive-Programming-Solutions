#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
#define FAST ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define pb push_back
#define pi pair<ll,ll>
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define fr(i,a,b) for(ll i = a;i < (ll)b;i++)
#define rfr(i,a,b) for(ll i = a;i > (ll)b;i--)
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define INF (ll)(1e18)
void io(){ios::sync_with_stdio(false) ;cin.tie(NULL) ;}
void dbg(vector<ll> tab){for(auto it : tab) cout<<it<<" ";cout<<endl;}
void dbgg(pi p){cout<<p.F<<" "<<p.S<<endl;}
void dbgpi(vector<pi> tab){for(auto it : tab) dbgg(it) ;}

const ll N = 2*1e5+1;


map<string,vector<string>> graph;
map<string,int>vis;
vector <ll> v,vs;
map <ll,ll> mp;
// set <ll> s;


void solve()
{
     v.clear();
     string s;
     int n,x,mx=0,res=0 ; cin >>n;
     if ( n==3)no
     else if (n%2){
          yes
               fr(i,0,n/2){
          cout << 1-n/2 << " "<< n/2<< " "; }
          cout <<1-n/2<< endl;
     
     }
     else{yes
     fr(i,0,n/2){
          cout << 1 << " "<< -1<< " "; 
     }
     cout <<  endl;
     }
     // fr( i,0,n)     res+= v[i]-mx;
     // cout << res <<endl;
}
int main()
{
     // cout << 5/3 << endl;
    FAST ;
    io() ;
    srand(time(0)) ;
     ll tt=1;
       cin >> tt;
    while (tt--)
        solve() ;
}



