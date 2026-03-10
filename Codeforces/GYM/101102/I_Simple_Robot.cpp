#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef long double ld ;
#define pb push_back
#define pi pair<ll,ll>
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define alll(x) ((x).begin()+1), (x).end()
#define mod mod
#define endl '\n'
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 998244353   ;
void io(){ios::sync_with_stdio(false) ;cin.tie(NULL) ;}
template<class T> bool ckmax(T& a, const T& b){return a < b ? a = b, 1 : 0;}
template<class T> bool ckmin(T& a, const T& b){return a > b ? a = b, 1 : 0;}
void nop(){cout<<-1<<endl;return;}


int n , m ;
string s;

int check1(int i)
{
    int curr = i ;
    int res = 0 ;
    for(char c : s){
        if(c=='^'){
            if(curr+1>n) res++ ;
            else curr++ ;
        }else if(c=='v'){
            if(curr-1<1) res++ ;
            else curr-- ;
        }
    }
    return res ;
}

int check2(int i)
{
    int curr = i ;
    int res = 0 ;
    for(char c : s){
        if(c=='>'){
            if(curr+1>m) res++ ;
            else curr++ ;
        }else if(c=='<'){
            if(curr-1<1) res++ ;
            else curr-- ;
        }
    }
    return res ;
}

void solve()
{
    cin>>n>>m ;
    cin>>s ;
    int l = 1 , r = n , best1 = n;
    while(l<=r){
        int md1 = l + (r-l)/3 ;
        int md2 = r - (r-l)/3 ;
        assert(md1<=md2) ;
        int x = check1(md1) , y = check1(md2) ;
        if(x<y){
            best1 = x ;
            r = md2-1 ;
        }
        else{
            best1 = y ;
            l = md1+1 ;
        }
    }
    l = 1 , r = m ;
    int best2 = m;
    while(l<=r){
        int md1 = l + (r-l)/3 ;
        int md2 = r - (r-l)/3 ;
        assert(md1<=md2) ;
        int x = check2(md1) , y = check2(md2) ;
        if(x<y){
            best2 =  x ;
            r = md2-1 ;
        }
        else{
            best2 = y ;
            l = md1+1 ;
        }
    }
    cout<<best1 + best2<<endl;


}


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.in","r",stdin) ;
        freopen("output.out","w",stdout) ;
    #endif
    io() ;
    ll tt = 1 ;
    cin>>tt ;
    while(tt--){
        solve() ;
    }

    return 0 ;
}