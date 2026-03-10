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
void dbg(vector<ll> tab){for(auto it : tab) cout<<it<<" ";cout<<endl;}
void dbgg(pi p){cout<<p.F<<" "<<p.S<<endl;}
void dbgmp(map<ll,ll> mp){for(auto p: mp) cout<<p.F<<" "<<p.S<<endl;}
void dbgpi(vector<pi> tab){for(auto it : tab) dbgg(it) ;}

const ll N = 1e6+7 , mod =1e9+7, Q =1e5+3 ;
vi primes ; 

vector <ll> sieve(int n ){
    vi vs(n+1,0), pri ;
    for  (int i =2 ; i<=n ; i++){
        if (!vs[i]){
            pri.pb ( i);
            for ( int j=i ; j<=n ; j+=i)
                vs[j]=1;
        }
    }
    return pri ;
}

void solve(){
    ll n , cnt =0 , res =0 ,ans =0 , nb =0 ;
    string ch ;
    cin >>ch ; 
    vi mp(ch.size()+1,0);
    for (ll i=0 ;i< ch .size() ; i++){
        if (ch[i]=='+')
            cnt ++;
        else
            cnt--;
        if (cnt<=0){
            res = max (res , abs(cnt));
        }
    }
    // watch(res);
    n = res+1 , cnt =0; 
    for (ll i=0 ;i< ch .size() ; i++){
        if (ch[i]=='+')
            cnt ++;
        else
            cnt--;
        ans   += n ;
        if ( cnt<0 && !mp[abs(cnt)]){
            n--;
            mp[abs(cnt)]++;
        }
        // watch(n);
    }
    cout << ans <<endl;

}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    FAST ;
    io() ;
    srand(time(0)) ;
    ll tt=1;
    primes = sieve(N);
    cin >> tt;
    while (tt--)
        solve() ;
}
