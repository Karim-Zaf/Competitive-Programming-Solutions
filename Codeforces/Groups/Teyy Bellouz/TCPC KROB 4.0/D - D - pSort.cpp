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

const ll N = 1e7+5 , MOD =1e9+7, Q =2e5+3 ;

vector<int>  sz , parent ; 
void init(int n){ for (int i = 0; i < n; i++){ parent.pb(i) ; sz.pb(1) ; } }
int get(int a){return (parent[a] == a ? a : parent[a] = get(parent[a]));}
bool unite(int a, int b){
    if ((a = get(a))==(b = get(b))) return false;
    if (sz[a]>sz[b]) swap (a,b) ; 
    parent[b] = a;
    sz[a] += sz[b]; 
    return true ; 
}
bool same_set(int a, int b){return get(a) == get(b);}
int size(int a){ return sz[get(a)];}

void solve (){ 
    int n ,x ; 
    cin >> n; 
    init(n+1) ; 
    vector<int > p(n+1) , v(n+1) ; 
    for (int i =1 ; i<=n ; i++ ) cin>> v[i] ; 
    for (int i =1 ; i<=n ; i++ ) {
        cin >> p[i]; 
        int k = i+p[i];
        int s = i-p[i];
        if ( k>=1 && k<=n)
            unite(k,i) ; 
        if ( s>=1 && s<=n)
            unite(s,i) ; 
    }
    for (int i= 1 ;i<=n ;i++){
        int a = get(i) ; 
        int b = get(v[i]);
        if ( a!= b){no return;}
    }
    yes


}


int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif 
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; int test_case=1;     
    // cin >> test_case ; 
    while (test_case--)  solve() ;
}