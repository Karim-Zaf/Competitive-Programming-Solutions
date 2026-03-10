//  (1/0+) WINS
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
void dbg(set<ll> tab){for(auto it : tab) cout<<it<<" ";cout<<endl;}
void dbgg(pi p){cout<<p.F<<" "<<p.S<<endl;}
void dbgmp(map<ll,ll> mp){for(auto p: mp) cout<<p.F<<" "<<p.S<<endl;}
void dbgpi(vector<pi> tab){for(auto it : tab) dbgg(it) ;}

const ll N = 1e5+9, mod =1e9+7, Q =1e5 ; 


void solve(){
    ll  n , mn1 =1e9,ok=0 , cnt =0, cnt2=0;
    ll mn2 = mn1;
     cin >>n ;
     vi v ( n);
     for (ll i=0 ;i<n ; i++){
        cin >> v[i];
        if (v[i]!=0 && v[i]!=1)ok=1;
        if ( v[i]==0)
            cnt++;
        if (v[i]==1)
            cnt2++;
    }

     if ( cnt > (n+1)/2){
         if ( cnt2>=1 && !ok ) {
            cout <<2 <<endl;
         }
         else {
            cout << 1 <<endl;
         }
     }
    else {
        cout << 0 <<endl;
    }
}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    FAST ;
    io() ;
    srand(time(0)) ;
    ll tt=1;
    cin >> tt;
    while (tt--)
        solve() ;
}