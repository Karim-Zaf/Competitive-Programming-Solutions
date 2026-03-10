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
 
const ll N = 1e7 + 5 , MOD =1e9+7, mod=1e9+7, Q =2e5+4 ;
 
void solve() {
    string x ; 
    cin>> x ;
    set <char>  s  ; 
    s.insert('A');
    s.insert('H');
    s.insert('I');
    s.insert('M');
    s.insert('O');
    s.insert('T');
    s.insert('U');
    s.insert('V');
    s.insert('W');
    s.insert('X');
    s.insert('Y');
 
    string z = x;
    reverse(all(z));
    for (auto e : z ){
        if (s.find(e)==s.end()){cout << "no" <<endl; return;}
    }
    if ( z == x){cout << "yes" <<endl; return;}
    cout << "no" <<endl;
}
 
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif  
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; int test_case=1;     
    cin >> test_case ; 
    while (test_case--)  solve() ;
}