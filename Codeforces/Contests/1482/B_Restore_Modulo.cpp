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
#define endl '\n'
#define MOD mod
#define INF (ll)(1e18)

const ll N = 1e7+5 , MOD =1e9+7, Q =2e5+3 ;

void solve (){   
    ll n ,g; 
    cin >> n  ; 
    map <ll,ll> mp ; 
    vi v(n) , diff , diff_two ; 
    for (ll i = 0 ;i<n ; i++ ){
        cin >> v[i] ; 
        if (i && !mp[v[i]-v[i-1]]){
            diff.pb(v[i]-v[i-1]) ; 
            mp[v[i]-v[i-1]]=1; 
        }
    }
    if (diff.size() <=1){  cout << 0 <<endl;return;   }
    for (ll i= 1 ; i<diff .size(); i++)
        diff_two.pb(abs(diff[i]-diff[i-1])) ; 
    g = diff_two[0] ; 
    for (auto d : diff_two ) g= __gcd ( d , g ) ;
    ll s = (v[0] +g)%g  ;
    ll  c= (v[1]-v[0] + g )%g ; 
    if (v[0]>= g) { cout << - 1<< endl; return ;}
    for (ll i= 1 ; i < n ; i++){
        if(v[i]!= (v[i-1]+c)%g ) {   cout << - 1 <<endl; return ; }
    } 
    cout << g << " "<< c <<endl;  
    
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif 
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; ll test_case=1;     
    cin >> test_case ; 
    while (test_case--)  solve() ;
}