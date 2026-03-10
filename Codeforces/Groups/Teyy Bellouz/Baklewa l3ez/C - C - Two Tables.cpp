//  (1/0+) WINS
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
#define pb push_back
#define pi pair<ll,ll>
#define vi vector<ll>
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define MOD mod
#define INF (ll)(1e18)
void dbg(vector<ll> tab){for(auto it : tab) cout<<it<<" ";cout<<endl;}
void dbgmp(map<ll,ll> mp){for(auto p: mp) cout<<p.F<<" "<<p.S<<endl;} 
void dbgg(pi p){cout<<p.F<<" "<<p.S<<endl;}
void dbgpi(vector<pi> tab){for(auto it : tab) dbgg(it) ;}

const ll N = 2e5+5 , MOD =1e9+7, Q =2e5+3 ;

void solve(){
    ll w , h , x1 , y1 , x2 , y2 , new_x , new_y;
    cin >> w >> h >> x1 >> y1 >> x2 >> y2 >> new_x >> new_y ; 
    ll dis_x = max ( x1 , w- x2) ;
    long double change_x =max(0ll, new_x -dis_x);
    // watch (change_x); 
        ll dis_y = max ( y1 , h- y2) ;
    long double change_y = max (0ll ,new_y -dis_y) ; 
    // watch (change_y); 
    // if (change_x + y2 -y1 > h){cout << -1 <<endl; return;}
    if (new_x + x2 -x1 > w && new_y + y2 - y1 > h){cout << -1 <<endl; return;} 
    else if (new_x + x2 -x1 > w && new_y + y2 - y1 <= h)cout << change_y <<endl;
    else if  (new_x + x2 -x1 <= w && new_y + y2 - y1 > h) cout <<change_x<<endl;
    else cout << min( change_x , change_y)<<endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ;
    ll tt=1;  ;   
    cin >> tt ;   
    while (tt--)
        solve() ;
}