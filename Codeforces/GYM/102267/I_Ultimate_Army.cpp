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
 
const ll N = 1e7+5, mod =1e9+7, Q =1e5 ;
 
void solve(){
    ll n , b;
    string ch; 
    cin >> b>> ch ;
    n = ch .size();
    // cout << n <<endl;
    vi res (b+1 , 0) ;  
    stack <ll> q ;
    for (ll i=0 ;i<n ; i++){
        string ss= "" ;
        ll k = i;
        if ( ch[i]>='0'&& ch[i]<='9'){
            ss +=ch[i];
            while (ch[i+1]>='0'&& ch[i+1]<='9'){
                ss += ch[i+1];
                i++;
            }
        }
        ll x =0 , cnt=1;
        for (ll j = ss .size()-1 ; j >= 0 ; j--){
            x+=(ss[j]-'0')*cnt; 
            cnt*=10;
        }
        // watch (x);
        if ( x ){
            if (i==0 || q.empty()){
            // watch(x);
                res[x]=0;
                q.push (x); 
            }
            else if ( ch[k-1]== '(' ){
                // watch(x);
                ll rass =  q.top();
                res[x]=rass;
                q.push (x);
            }
        }
        ll j =i, cnt1=0 , cnt2=0 ; 
        // while (ch[j]== '('){j++;cnt1++;}
        // while (ch[j]==')'){j++;cnt2++;}
        // if ( cnt1 ==  cnt2 && cnt1 !=0){
        //     i =j -1 ; 
        //     continue;
        // }
         if ( ch[i]==')'&& (ch[i-1]!='('||ch[i-1]==')'))
            q.pop();
    }
 
    for ( ll i=1 ; i<=b ; i++)
        cout <<res[i]<< " " ;
}
 
 
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    FAST ;
    io() ;
    srand(time(0)) ;
    ll tt=1;
    // cin >> tt;
    while (tt--)
        solve() ;
}