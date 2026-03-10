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
void dbgmp(map<string,ll> mp){for(auto p: mp) cout<<p.F<<" "<<p.S<<endl;}
void dbgpi(vector<pi> tab){for(auto it : tab) dbgg(it) ;}

const ll N = 1e18+5, mod =1e9+7, Q =1e5+3 ;

bool compare (string mn , string ch ){
    if ( ch.size()>mn.size())
        return 0;
    if ( ch.size()<mn.size())
        return 1;
    if ( ch[0]>mn[0])
        return 0;
    if ( ch[0]<mn[0])
        return 1;

    if ( ch[1]>mn[1])
        return 0;
    if ( ch[1]<mn[1])
        return 1;
    if ( ch[2]>mn[2])
        return 0;
    return 1;

}

void solve(){
    ll n,x ; 
    string ch, mn = "zzzzzz" ; 
    cin >> n >> ch ;
    ll z = compare ( "abc","aec");
    for (char a= 'a'; a <= 'z'; a++){
        string ch1="";
        ch1+=a;
        if (!(ch.find(ch1)!= string::npos)){
                if ( compare(mn,ch1)){
                    mn = ch1;
                }
            }
        for (char b= 'a'; b <= 'z'; b++){
            string ch2=ch1+b;
            if (!(ch.find(ch2)!= string::npos)){
                // watch(ch2);
                if (compare(mn,ch2)){
                    mn = ch2;
                }
            }
            for (char c= 'a'; c <= 'z'; c++){
                string ch3=ch2+c;
                if (!(ch.find(ch3)!= string::npos)){
                    if ( compare(mn,ch3)){
                        mn = ch3;
                    }
                }
            }
        }
    }
    cout << mn <<endl;
    
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