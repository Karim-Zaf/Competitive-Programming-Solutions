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
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define INF (ll)(1e18)
void io(){ios::sync_with_stdio(false) ;cin.tie(NULL) ;}
void dbg(vector<ll> tab){for(auto it : tab) cout<<it<<" ";cout<<endl;}
void dbgg(pi p){cout<<p.F<<" "<<p.S<<endl;}
void dbgmp(map<ll,ll> mp){for(auto p: mp) cout<<p.F<<" "<<p.S<<endl;}
void dbgpi(vector<pi> tab){for(auto it : tab) dbgg(it) ;}

const ll N = 1e5+7 , MOD =1e9+7, Q =1e5+3 ;

void solve(){
    ll n, sum  = 0 , two  =0 , three = 0 , x;
    cin >> n; 
    for (ll i=0 ; i<n ; i++){
        cin >> x;
        if (x==3) three++;
        else two++;
        sum += x;
    }
    if ( sum%3){ no return; }
    ll jdid = sum /3;
    // watch(jdid);
    
    if (jdid %6 ==2 &&two>=3){
        jdid-=2;
        two-=3;
    }
    else if ( jdid %6== 4  && two >=6 ){
        two-=6;
        jdid-=4;
    }
    else if ( jdid %6== 3  && three >=3 ){
        jdid -=  3 ;
        three -=3;
    }
    else if (jdid %6==5 && three >=3 && two >=3){
        three-=3;
        two -=3;
        jdid -=5;
    }
    else if ( jdid %6 ==1 && jdid>=7 && three>=3 &&two>=6){
        two-=6;
        jdid -=7;
        three -=3;
    }
    ll nw = jdid;
    for (ll i=0 ;i<3 ; i++){
        jdid  = nw;
        while (jdid>0){
            if (three >=2 ){
                three-=2;
                jdid-=6;
            }
            else if (two>=3){
                two-=3;
                jdid-=6;
            }
            else {no return;}
        } 
    }
    if (jdid){no return;}
    yes
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
