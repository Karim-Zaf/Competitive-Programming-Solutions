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

const ll N = 1e5 , mod =1e9+7, Q =1e5+3 ;

void solve(){
    ll n , res =0, h=0; 
    cin >> n ;
    string a , b ; 
    cin >> a >> b ;
    for (ll i=0 ;i<n ; i++){
        // watch(i);
        //     watch(res);
        ll one =0 , zero =0, ok=0; 
        while((!one || !zero)&& i<n){
            one += (a[i]=='1') + (b[i]=='1');
            zero += (a[i]=='0') + (b[i]=='0');
            if ((b[i]=='1'|| a[i]=='1') && (a[i]=='0'|| b[i]=='0')){
                res++;
                break;
            }
            if (one && zero){
                res++;
                break;
            }
            if (b[i]=='0'&& a[i]=='0'){
                if ( i < n-1 && (a[i+1]=='1'&& b[i+1]=='1')){
                    res++ ; i++;
                    ok =1;
                }
                else h++;
                break;
            }
            if (!one || !zero){
                i++;
                continue;
            }
        }
        // if (!ok )
        //     res++;
    }
    cout << res *2 +h <<endl;
    
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
