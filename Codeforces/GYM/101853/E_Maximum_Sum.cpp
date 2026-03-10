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

const int N = (1<<17) ;
vector<int> v[N] ;

int valid(int mask){
    for(int j = 0 ; j<16 ; j++){
        if((1<<j) & mask){
            if((1<<(j+1)) & mask){
                return 0 ;
            }
        }
    }
    return 1 ;
}
int a[20][20] ;
int dp[20][N] ;
int n ;
int work(int i , int mask){
    if(i==n) return 0 ;
    int& ret = dp[i][mask] ;
    if(ret!=-1) return ret ;
    ret = work(i+1 , 0) ;
    for(int nx : v[mask]){
        int sum = 0 ;
        for(int j = 0 ; j<n ; j++){
            if(nx & (1<<j)) sum += a[i][j] ;
        }
        ckmax(ret , work(i+1 , nx) + sum) ;
    }
    return ret ;
}

void solve() {
    cin>>n ;
    memset(dp , -1 , sizeof (dp)) ;
    int tot = 1<<n ; tot-- ;
    int sum = 0 ;
    for(int i = 0 ; i<(1<<n) ; i++){
        v[i].clear() ;
        if(!valid(i)) continue;
        int comp = tot ^ i ;
        for(int j = 0 ; j<n ; j++){
            if((1<<j) & i){
                int nj = j-1 ;
                if(nj>=0 && (1<<nj) & comp) comp ^= (1<<nj) ;
                nj +=2 ;
                if(nj<n && (1<<nj) & comp) comp ^= (1<<nj) ;
            }
        }
        for(int j = comp ; j>0 ; j = (j-1) & comp){
            if(!valid(j)) continue;
            v[i].pb(j) ;
        }
        sum += v[i].size() ;
    }
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<n ; j++){
            cin>>a[i][j] ;
        }
    }
    cout<<work(0 , 0)<<endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    io();
    int tt = 1;
    cin>>tt ;
    while (tt--) {
        solve();
    }

    return 0;
}