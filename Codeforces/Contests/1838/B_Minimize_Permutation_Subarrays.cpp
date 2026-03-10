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
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define non cout<<"-1\n";
#define F first
#define S second
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define INF (ll)(1e18)
template<typename T>void dbg(const T&x){for(auto&i:x)cout<<i<<' ';cout<<'\n';}

const ll N = 1e5 + 5 , MOD =1e9+7, mod=1e9+7, Q =2e5+4 ;

void solve(){
    long long  n ,res = 0 , x , mx = -INF ,ok = 1 ,un=0 , deux=0 , trois=0, quatre=0 ; 
    cin >> n ; 
    vector <int> v(n+1) ;
    map <ll,ll> pos ; 
    for (int i= 1 ;i<=n ;i++){
        cin >> v[i];
        pos [v[i]]= i ;
    }
    if ( pos[2] -1>pos[1] && (pos[n]> pos[2]|| pos[n]<pos[1]))cout << pos[n] << " " << pos[1]+1 <<endl;
    else if ( pos[2] -1>pos[1] )cout << pos[n] << " " << pos[n] <<endl;
    else if ( pos[2] +1 < pos[1] && (pos[n]< pos[2]|| pos[n]>pos[1]) ) cout << pos[n] << " " << pos[1]-1 <<endl;
    else if ( pos[2] +1 < pos[1] ) cout << pos[n] << " " << pos[n] <<endl;
    else if ( pos[2]> pos[1]){
        if (pos[n]> pos[2])
            cout << pos[2] << " " << pos[n] << endl;
        else cout << pos[1] << " " << pos[n] << endl;
    }
    else {
        if (pos[n]< pos[2])
            cout << pos[2] << " " << pos[n] << endl;
        else 
            cout << pos[1] << " " << pos[n] << endl;
    }


}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif  
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; int test_case=1;     
    cin >> test_case ; 
    while (test_case--)  solve() ;
}