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
 
const ll N = 1e6 + 4 , MOD =1e9+7, mod=1e9+7, Q =2e5+4 ;
 
vector <int> v, sieve[N] , vis (N),  mp (N);
 
void solve(){
    int n , h , w ;
    cin >> n >> h >> w ;
    for (int i=  0 ;i<n ;i++){
        char to_work , to_home ; 
        cin >> to_home >> to_work ;
        if (to_home == 'Y' || !w){
            h--;
            w++;
            cout << 'Y' << " ";
        }else cout << 'N' << " ";
        if (to_work=='Y' || !h){
            w-- ;
            h++;
            cout << 'Y' << endl;
        }else cout << 'N' << endl;
    }
}
 
int32_t main(){
   #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
   #endif
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; int test_case=1;
    // cin >> test_case ;
    while (test_case--)  solve() ;
 
}