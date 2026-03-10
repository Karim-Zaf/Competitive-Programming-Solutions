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

void solve(){
    int n ; 
    cin >>n ;
    char t[n][n];
    for ( ll i=0 ;i<n ;i++)
        for ( ll j=0 ;j<n ;j++) 
            cin >> t[i][j];
    if ( t[0][1]==t[1][0]&& t[n-1][n-2]==t[n-2][n-1] && t[n-2][n-1]!=t[1][0]){
        cout << 0 <<endl;
        return;
    }
    if ( t[0][1]==t[1][0]&& t[n-1][n-2]==t[n-2][n-1] && t[n-2][n-1]==t[1][0])
        cout << 2 <<endl << 1 << " "<< 2 <<endl << 2 << " " <<  1 <<endl;
    else if(t[0][1]==t[1][0] && t[n-1][n-2]==t[1][0] )
        cout << 1 << endl << n << " "<<n-1<<endl;
    else if(t[0][1]==t[1][0] && t[n-2][n-1]==t[1][0] )
        cout << 1 << endl << n-1 << " "<<n<<endl;
    else if(t[n-1][n-2]==t[n-2][n-1] && t[n-2][n-1]==t[1][0] )
        cout << 1 << endl << 2 << " "<<1<<endl;
    else if(t[n-1][n-2]==t[n-2][n-1] && t[n-2][n-1]==t[0][1] )
        cout << 1 << endl << 1 << " "<<2<<endl;
    else if  (t[n-1][n-2]==t[1][0] )
        cout << 2 <<endl << n <<" "<<n-1 <<endl << 1 << " " << 2 <<endl;
    else
        cout << 2 <<endl << n <<" "<<n-1 <<endl << 2 << " " << 1 <<endl;
}
int main(){
    #ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin);freopen("outputt.txt","w",stdout);
     #endif
     FAST ;
     io() ;
     srand(time(0)) ;
     ll tt=1;
     cin >> tt;
     while (tt--)
          solve() ;
}