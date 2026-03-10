#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define pi pair<ll,ll>
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define alll(x) ((x).begin()+1), (x).end()
#define clean(v) (v).resize(distance((v).begin(), unique(all(v))));
#define yes cout<<"Yes"<<endl;
#define no cout<<"No"<<endl;
#define mod mod
#define endl '\n'
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 998244353;
 
void io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}
 
template<class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
 
template<class T>
bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
 
void nop() {
    cout << -1 << endl;
    return;
}
 
 
 
 
struct point{
    ll x{} , y{} ;
    point(){
        x = 0 ;
        y = 0 ;
    }
    point(ld xx , ld yy){
        x = xx ;
        y = yy ;
    }
    bool operator < (const point& b) const{
        return make_pair(x , y)< make_pair(b.x , b.y) ;
    }
    bool operator <= (const point& b) const{
        return make_pair(x , y)<= make_pair(b.x , b.y) ;
    }
    bool operator == (const point& b) const{
        return make_pair(x , y)== make_pair(b.x , b.y) ;
    }
    ll operator * (const point& b) const{
        return y*b.x - x*b.y ;
    }
    point operator - (const point& b) const{
        return point(x-b.x , y-b.y) ;
    }
    point operator + (const point& b) const{
        return point(x+b.x , y+b.y) ;
    }
    point operator * (const ld& k) const{
        return point(x*k , y*k) ;
    }
    point operator / (const ld& k) const{
        return point(x/k , y/k) ;
    }
 
    long long triangle(const point& b ,const point& c) const{
        return (b - *this) * (c - *this) ;
    }
 
 
};
 
void print(point p){
    cout<<"p.x = "<<p.x<<" p.y = "<<p.y<<endl;
}
 
const long double PI = acos(-1) ;
 
point read()
{
    point p ;
    cin>>p.x>>p.y ;
    return p ;
}
 
int work(point a , point b)
{
    return 1 + __gcd((int)abs(a.x - b.x) , (int)abs(b.y - a.y)) ;
}
 
void solve() {
    int n ; cin>>n ;
    ll area = 0 ;
    point p = read() ;
    point lst = p ;
    point p1 ;
    ll b = -n ;
    for(int i = 1  ; i<n ; i++){
        p1 = read() ;
        area += lst*p1 ;
        b += work(lst , p1) ;
        lst = p1 ;
    }
    b += work(lst , p) ;
    area += lst*p ;
    area = abs(area) ;
    cout<<(area - b +2)/2<<endl;
 
}
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    io();
    ll tt = 1;
    //cin>>tt ;
    while (tt--) {
        solve();
    }
 
    return 0;
}