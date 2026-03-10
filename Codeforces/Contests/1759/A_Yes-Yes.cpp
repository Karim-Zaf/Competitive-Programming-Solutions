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
	string s; cin >> s;
	char x=s[0];
	if(x!='e'&& x!='s'&& x!='Y'){no return;}
	for (ll i =1; i <s.size();i++){
	     
	     char j = s[i];
	     if(x=='s'&&j=='Y'|| x=='Y'&&j=='e'||x=='e'&& j=='s')
	     {
	          x=j;
	     }
	     else {no return;}
	}
	yes//cout <<  << endl;
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