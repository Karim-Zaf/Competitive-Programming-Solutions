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
void dbg(vector<string> tab){for(auto it : tab) cout<<it<<" ";cout<<endl;}
void dbgg(pi p){cout<<p.F<<" "<<p.S<<endl;}
void dbgpi(vector<pi> tab){for(auto it : tab) dbgg(it) ;}

const ll N = 202;

map<string,vector<string>> graph;
map<string,int>vis;
vector <ll> v;
map <ll,ll> mp;
set <ll> s;
int res=2,mx=0;

void solve()
{

        int x,y, x2,y2, x3,y3; cin>> x>>y>> x2>>y2>> x3>>y3;
        if ( x!=x2 && x2!=x3 && x3!=x || y3!=y&&y!=y2 && y2!=y3)yes
            else no


}
int main()
{
    FAST ;
    io() ;
    srand(time(0)) ;
     ll tt=1;
       cin >> tt;
    while (tt--)
        solve() ;
}



