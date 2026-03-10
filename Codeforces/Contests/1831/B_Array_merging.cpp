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

const ll N = 1e6+5 , MOD =1e9+7, Q =2e5+3 ;

void solve (){
    int n ,res = 1 ; 
    cin >> n ; 
    vi b(n) , v(n) ;
    map <int ,int > mp1 , mp2 ;
    for (int i= 0 ;i<n ; i++ ) cin >> v[i] ; 
    for (int i= 0 ;i<n ; i++ ) cin >> b[i] ; 
    mp1[v[0]]=1 ;
    int i = 1 ;
    while (i<n){
        int cmpt=1 ;
        mp1[v[i]] = max (mp1[v[i]],1) ; 
        res = max (res , mp1[v[i]]) ;
        if (v[i] == v[i-1]){
            int cmpt = 2 , h = v[i] ;
            i++;
            while ( v[i] ==v[i-1] && i<n ) {
                i++ ; cmpt ++ ;
            }
            mp1[h] = max (mp1[h],cmpt) ;
            res = max (res , mp1[h]) ;
        }
        else i++ ;
    }
     i = 1 ;
    mp2[b[0]]=1 ;
    while (i<n){
        res = max (res , mp1[b[i]]) ;
        mp2[b[i]] = max (mp2[b[i]],1) ; 
        if (b[i] == b[i-1]){
            int cmpt = 2 , h = b[i] ;
            i++;
            while ( b[i] ==b[i-1] && i<n ) {
                i++ ; cmpt ++ ;
            }
            mp2[h] = max (mp2[h],cmpt) ;
            res = max (res , mp2[h]) ;
        }
        else i++ ;
    }
    for (auto x : mp1) {
            res = max (res , mp1[x.F]+mp2[x.F]) ;

    }
    cout << res <<endl;

}



int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif  
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; int test_case=1;     
    cin >> test_case ; 
    while (test_case--)  solve() ;
}