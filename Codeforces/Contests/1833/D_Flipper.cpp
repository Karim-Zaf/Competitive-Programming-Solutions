
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
    int n , k ; 
    cin >> n  ; 
    vi v(n) , pref(n), rs ;
    vector <pair<int , int >> vp ; 
    for (int i = 0 ;i<n ;i++) {
        cin >> v[i] ; 
        vp.pb({v[i] , i }) ;
    }
    sort (rall(vp)) ; 
    // kar (vp);
    if (n==1){cout << 1<<endl; return;}
    if (v[0]==n){
        if (v[n-1]== n-1 ) {
            cout << v[n-1] << " "; 
            for (int i= 0; i<n-1 ; i++) cout << v[i] <<" ";cout <<endl;
            return; 
        }
        for (int i= vp[1].S; i<n ; i++) cout << v[i] <<" ";
            cout << v[vp[1].S-1] << " "; 
        for (int i= 0; i<vp[1].S-1 ; i++) cout << v[i] << " " ; cout<<endl;
        return; 
    }
    int i_mx = vp[0].S ; 
    int i_mn = i_mx , cmp = -1  ;
    for (int i= (vp[0].S == n-1 ? i_mx-1 : i_mx-2) ; i>=0 ;i--){ 
        if ( v[i]<=v[0]){
            i_mn = (i<i_mx? i+1 : i ) ;
            break;}
        i_mn ; 
    }
    for(int i = i_mx ; i<n ; i++ )  rs.pb(v[i]);
    for(int i = i_mx-1 ; i>=i_mn ; i-- ) rs.pb(v[i]);
    for(int i = 0 ; i<i_mn ; i++ )rs.pb(v[i]);
    for (auto x : rs) cout << x << " "; cout <<endl; 

}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif 
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; ll test_case=1;     
    cin >> test_case ; 
    while (test_case--)  solve() ;
}