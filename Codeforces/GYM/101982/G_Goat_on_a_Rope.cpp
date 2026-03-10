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
 
 
double calc(ll fir , ll sec){
    double ans = sqrt(fir * fir + sec * sec);
    return ans;
}
 
 
void solve() {
    ll x,y,x1,y1,x2,y2;
    cin>>x>>y>>x1>>y1>>x2>>y2;
    ll low_x, low_y, high_x, high_y;
    low_x = min(x1, x2);
    low_y = min(y1, y2);
    high_x = max(x1, x2);
    high_y = max(y1, y2);
    x1 = low_x;
    x2 = high_x;
    y1 = low_y;
    y2 = high_y;
 
    ll dis1=0, dis2=0;
 
 
    if (x>=x2 && y>=y2){
        dis1 = abs(x-x2);
        dis2 = abs(y-y2);
 
        double ans = calc(dis1, dis2);
        cout<<fixed<<setprecision(3)<<ans;
        return;
    }
    else if (x>=x2 && y<=y1){
        dis1 = abs(x-x2);
        dis2 = abs(y - y1);
        double ans = calc(dis1, dis2);
        cout<<fixed<<setprecision(3)<<ans;
        return;
    }
    else if (x<=x1 && y>=y2){
        dis1 = abs(x-x1);
        dis2 = abs(y-y2);
        double ans = calc(dis1 , dis2);
        cout<<fixed<<setprecision(3)<<ans;
        return;
    }
    else if (x<=x1 && y<=y1){
        dis1 = abs(x-x1);
        dis2 = abs(y-y1);
        double ans = calc(dis1, dis2);
        cout<<fixed<<setprecision(3)<<ans;
        return;
    }
    else if (x>=x2 && y>=y1 && y<=y2){
        double ans = x-x2;
        cout<<fixed<<setprecision(3)<<ans;
        return;
    }
    else if (y>=y2 && x>=x1 && x<=x2){
        double ans = y - y2;
        cout<<fixed<<setprecision(3)<<ans;
        return;
    }
    else if (x>=x1 && x<=x2 && y<=y1){
        double ans = y1 - y;
        cout<<fixed<<setprecision(3)<<ans;
        return;
    }
    else if (x<=x1 && y>=y1 && y<=y2){
        double ans = x1-x;
        cout<<fixed<<setprecision(3)<<ans;
        return;
    }
 
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