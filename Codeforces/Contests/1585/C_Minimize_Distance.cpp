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
     v.clear();
	ll n,k; cin >> n>> k;
	for (ll x, i = 0; i < n; i++) {
		cin >> x; v.push_back(x);
	}
	sort ( v.begin(),v.end());
	ll  res = 0, j = n - 1, i = 0;

	while (v[j]> 0 && j>=0 ||  v[i] < 0 && i < n) {
		
		if (v[i] < 0 && i < n) {
			res += 2* abs(v[i]);
			i += k;
		}
		 if (v[j] > 0 && j >= 0){
			res += 2* abs(v[j]);
			j -= k;
		}
	}
		if (abs(v[0]) > abs(v[n-1])) 
		res -= abs(v[0]);
	else 	res -= abs(v[n-1]);

	cout << res << endl;       
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