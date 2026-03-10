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

vector <ll> graph[N];
vector <ll> allez , retour;
bool vis[N];

void solve(){
    string ch; 
    string res1="", res2 ="", fin1 , fin2;
    cin >> ch ;
    ll n = ch.size();
    ll i=0 , j=n-1;
    while ( ch[i]==ch[j] && j>i){
        res1+=ch[i];
        res2=ch[j]+res2;
        i++;
        j--;
    }
    if ( ch[i]==ch[j]&&j==i)res1+=ch[i];
    
    for (ll k =i; k<=j ;k++){
        ll lef=k , righ=j ;
        
        string resal1="" , resal2="";
        while (ch[lef]==ch[righ]&& lef <righ){
            resal1+=ch[lef];
            resal2=ch[righ]+resal2; 
            lef++;
            righ--;
        }
        if  ( ch[lef]==ch[righ]&&lef==righ)resal1+=ch[righ];
        string chila= res1 + resal1 + resal2 +res2;
        if (lef >= righ && chila.size()>fin1.size()){
            fin1= res1 + resal1 + resal2 +res2;
        }
    } 
    for (ll k =j; k>=i ;k--){
        ll lef=i , righ=k ;
        string resal1="" , resal2="";
        while (ch[lef]==ch[righ]&& lef <righ){
            resal1+=ch[lef];
            resal2=ch[righ]+resal2;
            lef++;
            righ--;
        }
        if  ( ch[lef]==ch[righ] &&lef==righ )resal1+=ch[righ];
        string chila= res1 + resal1 + resal2 +res2;
        if (lef >= righ && chila.size()>fin2.size() ){
            fin2= chila;
        }
    } 
    string res= res1 +res2;
    if ( n==1)cout << res1 <<endl;
    else if ( res.size()>fin1.size() &&res.size()>fin2.size() && !res.empty() || res.size()==ch.size())
        cout << res<<endl;
    else if ( fin2.size()>=fin1.size() && !fin1.empty())
        cout << fin2<<endl;
    else if ( fin1.size()>fin2.size() && !fin2.empty())
        cout << fin1 << endl;
    else
        cout << ch[0]<<endl;


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