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

void solve()
{
    ll n ,s=0, q ,mn=0; cin >> n >>q;
    ll tab[n];

    for (ll i=0; i < n; i++){
        cin >> tab[i]; 
        if (tab[i]==1)s++;
    }
    for (ll i=0; i < q; i++){
        ll t , op ; cin >> t >> op ; 
        if (t==1){
            
            tab[op-1]=1-tab[op-1];
            if ( tab[op-1]==0)s--;
            else s++;
        }
        else{
            if ( op > s) cout << 0 <<endl;
            else cout << 1 << endl;
        }
    }
}
 
int main()
{
    FAST ;
    io() ;
    srand(time(0)) ;
    //ll tt ; cin >> tt ;
    //for(ll i = 1 ; i<=tt ; i++)
        solve() ;
}