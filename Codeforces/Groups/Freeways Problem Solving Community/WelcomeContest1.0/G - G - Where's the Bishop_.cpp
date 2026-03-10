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
char tab[8][8];
void solve()
{
    string lj; getline (cin,lj);
    for (int j =0; j<8; j++)
        for (int i=0; i < 8; i++){
            cin >> tab[j][i];
            //cout << tab[j][i] ;
    
      }
    for (int j =1,s ,r; j<7; j++)
        for (int i=0; i < 8; i++)
              if (tab[j][i]=='#' && tab[j+1][i+1]=='#' && tab[j-1][i-1]=='#' && tab[j+1][i-1]=='#'&& tab[j-1][i+1]=='#')
                  cout << j+1<<" " <<i+1 << endl ;
}
 
int main()
{
    FAST ;
    io() ;
    srand(time(0)) ;
    ll tt ; cin >> tt ;
    for(ll i = 1 ; i<=tt ; i++)
        solve() ;
}