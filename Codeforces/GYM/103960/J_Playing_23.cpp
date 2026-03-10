#include<bits/stdc++.h>
 
using namespace std;
 
//mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());
//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")
//typedef __int128 lll;
 
#define ll long long
#define ld long double
#define watch(x) cout << (#x) << " is " << (x) << endl
#define PI 3.1415926535897932384626433832795
#define EULER 2.7182818284590452353602874713
#define F first
#define S second
#define pb push_back
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define sz(x) (int((x).size()))
 
const ll mod = 1e9 + 7;
const ll INF = 1e18 ;
const ll MIN = -1e18 ;
const ll MAXII = 100005 ;
 
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template<typename T> T lcm(T a, T b){return(a*(b/gcd(a,b)));}
 
 
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i*i<=a;++i) if (a%i==0) return 0; return 1; }
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
void dbg(vector<ll> v){for (auto x : v) cout << x << " "; cout << endl;}
void dbgg(pair<ll, ll> p){cout << p.F << " " << p.S << endl;}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }
 
 
 
void solve() {
    int n; cin>>n;
    multiset<ll>s;
    for (int i=0; i<4; i++){
        for (int j=1; j<=13; j++)
            s.insert(j);
    }
 
    int a1, a2; cin>>a1>>a2;
    s.erase(s.find(a1));
    s.erase(s.find(a2));
    if (a1>=10)
        a1=10;
    if (a2>=10)
        a2=10;
 
    int john = a1+a2;
    int b1,b2; cin>>b1>>b2;
    s.erase(s.find(b1));
    s.erase(s.find(b2));
 
    if (b1>=10)
        b1=10;
    if (b2>=10)
        b2=10;
    int mary = b1+b2;
    vector<ll>cards;
    int tot =0;
    for (int i=0; i<n ; i++){
        int a; cin>>a;
        s.erase(s.find(a));
        if (a>10)
            a=10;
        tot+=a;
        cards.pb(a);
    }
 
    int mini1 = 23 - (mary + tot);
    if (s.find(mini1)==s.end())
        mini1= 11;
 
    int mini2= 11;
//    watch(john+tot);
    auto it_mini2 = s.lower_bound(24 - (john+tot));
//    watch(*it_mini2);
 
    while (it_mini2 !=s.end()){
        ll curr = (*it_mini2);
        if (curr>10)
            curr=10;
        if (mary+tot + curr <=23){
            mini2 = (*it_mini2);
            break;
        }
        else
            break;
    }
 
//    watch(mini1);
//    watch(mini2);
 
    int res = min(mini1, mini2);
    if (res>10){
        cout<<-1;
        return;
    }
    cout<<res;
 
 
 
}
 
 
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
 
    int tc=1;
//    cin >> tc;
    while(tc--) {
        solve();
    }
}