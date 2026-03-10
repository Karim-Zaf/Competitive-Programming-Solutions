#include<bits/stdc++.h>
 
using namespace std;
 
//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")
//typedef __int128 lll;
 
#define ll long long
#define ld long double
#define watch(x) cout << (#x) << " is " << (x) << endl
#define PI 3.1415926535897932384626433832795
#define EULER 2.7182818284590452353602874713
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }
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
 
 
//mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i*i<=a;++i) if (a%i==0) return 0; return 1; }
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
void dbg(vector<ll> v){for (auto x : v) cout << x << " "; cout << endl;}
void dbgg(pair<ll, ll> p){cout << p.F << " " << p.S << endl;}
 
 
 
void solve() {
    ll n; cin>>n;
    string ch; cin>>ch;
    int rock[1005];
    int paper[1005];
    int sci[1005];
 
    memset(rock,0,sizeof(rock));
    memset(paper,0,sizeof(paper));
    memset(sci,0,sizeof(sci));
 
    if (ch[0]=='R')
        rock[0]=1;
    else if (ch[0]=='P')
        paper[0]=1;
    else
        sci[0]=1;
 
    for (int i=1; i<n; i++){
        rock[i]= rock[i-1]+ (ch[i]=='R');
        paper[i]= paper[i-1]+ (ch[i]=='P');
        sci[i]= sci[i-1]+ (ch[i]=='S');
    }
//    for (int i=0; i<n; i++)
//        cout<<rock[i]<<" ";
//    cout<<endl;
//    for (int i=0; i<n; i++)
//        cout<<paper[i]<<" ";
//    cout<<endl;
//    for (int i=0; i<n; i++)
//        cout<<sci[i]<<" ";
//    cout<<endl;
 
    ll res=0;
    for (int i=0; i<=n; i++){
        ll j=0, k=n;
        while(j<=k){
            if ((i+j+k)>n)
                k--;
            else if ((i+j+k)<n)
                j++;
            else{
 
                ll me=0;
                ll him=0;
                if (i>=1){
                    me+=(sci[i-1]);
                    him+=(paper[i-1]);
                }
 
 
                if (j>=1){
                    me+=(rock[i+j-1]-rock[i]+ (ch[i]=='R'));
                    him+=(sci[i+j-1]-sci[i]+ (ch[i]=='S'));
                }
 
                if (k>=1){
                    me+=(paper[n-1]-paper[i+j]+ (ch[i+j]=='P'));
                    him+=(rock[n-1]-rock[i+j]+ (ch[i+j]=='R'));
                }
 
                if (me>him){
 
                    res++;
                }
 
                me=0;
                him=0;
                if (k!=j){
 
                    if (i>=1){
                        me+=(sci[i-1]);
                        him+=(paper[i-1]);
                    }
 
 
                    if (k>=1){
                        me+=(rock[i+k-1]-rock[i]+ (ch[i]=='R'));
                        him+=(sci[i+k-1]-sci[i]+ (ch[i]=='S'));
                    }
 
                    if (j>=1){
                        me+=(paper[n-1]-paper[i+k]+ (ch[i+k]=='P'));
                        him+=(rock[n-1]-rock[i+k]+ (ch[i+k]=='R'));
                    }
 
                    if (me>him){
 
                        res++;
                    }
                }
 
 
                j++;
                k--;
            }
        }
    }
    cout<<res<<"\n";
 
}
 
 
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
 
    int tc;
    cin >> tc;
    while(tc--) {
        solve();
    }
}