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
void io(){ios::sync_with_stdio(false) ;cin.tie(NULL) ;//freopen("problem1.in","r",stdin) ;freopen("problem1.out","w",stdout) ;
}
void dbg(vector<ll> tab){for(auto it : tab) cout<<it<<" ";cout<<endl;}
void dbgg(pi p){cout<<p.F<<" "<<p.S<<endl;}
void dbgpi(vector<pi> tab){for(auto it : tab) dbgg(it) ;}
 
map <ll,ll> mp;
vector<ll> v,res;

void solve()
{
     mp.clear();
     ll m ,mx=0, s,x,j=1, sum=0; cin >>m>>s;
     for ( ll i =0;i<m;i++){
          cin>>x; mp[x]++;mx=max(mx,x);
     }
     while (sum <s || j<=mx){
//cout <<j<<endl;
          if(!mp[j])//{
               sum+=j;//cout <<j<<endl;}
               j++;
     }
     //cout <<sum<<endl;
	if (sum==s){yes return;}//cout <<  << endl; 
	no
}
 
int main()
{
    FAST ;
    io() ;
    srand(time(0)) ;
    ll tt; cin >> tt;
    while (tt--)
        solve() ;
}