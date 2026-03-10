/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
#ifndef ONLINE_JUDGE
#include "debug.cpp"
#else
#define kar(...)   
#endif
#define pb push_back
#define pi pair<ll,ll>
#define vi vector<ll>
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"
#define MOD mod
#define INF (ll)(1e18)

const ll N = 2e5+5 , MOD =1e9+7, Q =2e5+3 ;

struct Matrix {
    long long a[3][3] ={{0,0,0},{0,0,0},{0,0,0}};
    Matrix operator * ( Matrix  other) {
        Matrix product ;
        for (int i= 0 ;i<3 ; i++)
            for (int j = 0 ; j<3 ; j++)
                for (int k = 0 ; k<3 ; k++){
                    product.a[i][j]+= (a[i][k] * other.a[k][j])%MOD ; 
                    product.a[i][j]%=MOD ;
                }
        return   product ;
    }
};

void print(Matrix s ){
    for (int i= 0 ;i<3 ; i++){
        for (int j = 0 ; j<3 ; j++)
            cout << s.a[i][j] << " ";
        cout <<endl;
    }
    cout <<endl;
}

Matrix expo_power(Matrix a, int k){
    Matrix res ;
    res.a[0][0]=1 ;
    res.a[1][1]=1 ;
    res.a[2][2]=1 ;
    while (k>0){
        if (k % 2) 
            res = res * a; 
        a = a*a ;
        k/=2 ;
    }
    return res ;
}
void solve (){
    int n ; 
    cin >> n;
    Matrix m ;
    m.a[0][0]=1 ;
    m.a[0][1]=2 ;
    m.a[0][2]=3 ;
    m.a[1][0]=4 ;
    m.a[1][1]=5 ;
    m.a[1][2]=6 ;
    m.a[2][0]=7 ;
    m.a[2][1]=8;
    m.a[2][2]=9 ;
    Matrix res = expo_power(m,n-1);
    long long r = 0 ;
    for (int i= 0 ;i<3 ; i++)
        for(int j= 0; j<3 ; j++){
            r += res.a[i][j];
            r%=MOD;
        }
    // print(res);
    cout << r <<endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif  
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; int test_case=1;     
    cin >> test_case ; 
    while (test_case--)  solve() ;
}