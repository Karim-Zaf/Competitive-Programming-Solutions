/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#ifndef ONLINE_JUDGE
#include "debug.cpp"
#else
#define kar(...)
#endif
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define int ll
#define endl '\n'
 
const int  N=2e5+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;
 
int n , m , k ;
 
struct Matrix {
    long long a[105][105] ;
    void init (){
        for (int i= 0;i<105; i++)
            for (int j= 0 ;j<105; j++)
                a[i][j]=0;
    }
    Matrix operator * ( Matrix  other) {
        Matrix product ;
        product.init ();
        for (int i= 0 ;i<105 ; i++)
            for (int j = 0 ; j<105 ; j++)
                for (int k = 0 ; k<105 ; k++){
                    product.a[i][j]+= (a[i][k] * other.a[k][j])%MOD ;
                    product.a[i][j]%=MOD ;
                }
        return product ;
    }
};
 
void print(Matrix s ){
    for (int i= 0 ;i<10 ; i++){
        for (int j = 0 ; j<10 ; j++)
            cout << s.a[i][j] << " ";
        cout <<endl;
    }
    cout <<endl;
}
 
Matrix expo_power(Matrix a, long long k){
    Matrix res ;
    res.init();
    for (int i=0 ; i<105 ; i++)
        res.a[i][i] = 1 ;
    while (k){
        if (k % 2)
            res = res * a;
        a = a*a ;
        k/=2 ;
    }
    return res ;
}
 
 
 
void Solve() {
    cin>> n >> m >> k ;
    Matrix mt ;
    mt.init();
    for (int i= 1, u , v; i<=m ; i++){
        cin >> u >> v ;
        mt.a[u][v]++ ;
        mt.a[v][u]++ ;
    }
    Matrix res;
    res.init();
    res= expo_power(mt,k) ;
 
    int ans = 0;
    for (int i= 1;i<=n;i++) (ans += res.a[1][i])%=mod;
    cout << ans <<endl;
}
 
int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);ll Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}