//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,sse4a,avx,avx2,popcnt,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
#ifndef ONLINE_JUDGE
#include "dbg.cpp"
#else
#define dbg(...)
#endif
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define pb(n) push_back(n)
#define F first
#define S second
#define mp(x, y) make_pair(x, y)
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define nop cout << -1 << endl;
#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
const ll sup = 1e18;
const ll inf = -1e18;
const ll mod = 1e9 + 7;
const int N_Max = 3e5 + 7;
const int Nax = 1e6 + 5;
const int LOG = 20;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}


int add(int a , int b){
    return ( a + 0ll + b ) % mod ; 
}
int mult(int a , int b){
    return a * 1ll * b % mod ;
}
int sub(int a , int b){
    return (a - 0ll - b + mod ) % mod ;
}
int divide(int a , int b){
    return a * 1ll * inv(b) % mod ; 
}
//matrix_expo
 
const int N_mat=5;
 
struct Matrix {
    long long a[N_mat][N_mat] ;
    Matrix(){
        for (int i= 0; i<N_mat; i++)
            for (int j= 0; j<N_mat; j++)
                a[i][j]= 0 ;
    }
    Matrix operator * ( Matrix  other) {
        Matrix product ;
        for (int i= 0 ;i<N_mat ; i++)
            for (int j = 0 ; j<N_mat ; j++)
                for (int k = 0 ; k<N_mat ; k++)
                    product.a[i][j] = add(product.a[i][j] ,  mult(a[i][k] , other.a[k][j])) ;
                
        return product ;
    }
};
 
void print(Matrix s ){
    for (int i= 0 ;i<N_mat ; i++){
        for (int j = 0 ; j<N_mat ; j++)
            cout << s.a[i][j] << " ";
        cout <<endl;
    }cout <<endl;
}
 
Matrix expo_power(Matrix a, long long k){
    Matrix ret ;
    for (int i=0 ; i<N_mat ; i++) ret.a[i][i] = 1 ; //identity
    while (k){
        if (k % 2)
            ret = ret * a;
        a = a*a ;
        k/=2 ;
    }
    return ret ;
}

void solve(){
    ll n ;
    cin >> n ;
    Matrix M ; 
    for(int i = 0 ; i < 4 ; i++) M.a[0][i] = 1;
    for(int i = 1 ; i <= 4 ; i++){
        for(int j = 1 ; j <= 4 ; j++){
            if(i == j) continue ;
            M.a[i][j] = 1;
        }
    }
    M = expo_power(M , n - 1) ;
    int ans = 0;
    for(int i = 1 ; i < 4 ; i++) ans = add(ans , M.a[0][i]) ;
    cout << ans << endl;
}

int main(){
    FAST
    #ifndef ONLINE_JUDGE
    freopen("inputf.txt","r",stdin);
    freopen("outputf.txt","w",stdout);
    #endif
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}