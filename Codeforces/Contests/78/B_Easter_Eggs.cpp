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
void io(){ios::sync_with_stdio(false) ;cin.tie(NULL) ;}
void dbg(vector<ll> tab){for(auto it : tab) cout<<it<<" ";cout<<endl;}
void dbgg(pi p){cout<<p.F<<" "<<p.S<<endl;}
void dbgpi(vector<pi> tab){for(auto it : tab) dbgg(it) ;}

vector <ll> v;
map <ll,ll> mp;
set <ll> s;


void solve()
{
      int n ; cin >> n ;
      char t[] ={'R','O','Y'},ta[]={'G','B','I','V'};
      for ( int i =0; i< min(n,3) ; i++)
          cout << t[i];
          
     for ( int i=3;i<n;i++)
          cout <<ta[i%4];
      
}
 
int main()
{
//    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    FAST ;
    io() ;
    srand(time(0)) ;
     ll tt=1;
     //  cin >> tt;
 
    while (tt--)
        solve() ;
}