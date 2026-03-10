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

void solve(){
    string ch1 , ch2; 
    cin>> ch2 ; 
    ch1 = ch2 ; 
    int mn = 10 , n = ch1 .size() ,one = 0 , two = 0 ;
    for (int i= 0 ;i<n ; i++){
        if (i%2 && ch1[i]=='?') ch1[i]= '0';
        if (i%2==0 && ch1[i]=='?') ch1[i]= '1';
    }
    for (int i= 0 ;i<n ; i++){
        if (i%2 && ch2[i]=='?') ch2[i]= '1';
        if (i%2==0 && ch2[i]=='?') ch2[i]= '0';
    }
    one = 0 , two = 0 ;
    for (int i= 0 ;i<n ; i++){
        if (i%2==0 && ch1[i]=='1') one ++ ; 
        else if (ch1[i]=='1') two ++ ;
        int sum = 0 , sum2 = 0 ;
        for (int j = i+1 ; j<n ; j+=2) sum ++;
        for (int j = i+2 ; j<n ; j+=2) sum2 ++;
        if (i %2==0 && one > two+sum ) {mn = min (mn , i+1 ) ;}
        if (i %2 && two >one + sum ) {mn = min (mn , i+1 ) ;}
        if (i %2==0 && one+ sum2 <two ) {mn = min (mn , i+1 ) ;}
        if (i %2 && two + sum2 <one ) {mn = min (mn , i+1 ) ;}
    }
    one = 0 , two = 0 ;
    for (int i= 0 ;i<n ; i++){
        if (i%2==0 && ch2[i]=='1') one ++ ; 
        else if (ch2[i]=='1') two ++ ;
        int sum = 0 , sum2 = 0 ;
        for (int j = i+1 ; j<n ; j+=2) sum ++;
        for (int j = i+2 ; j<n ; j+=2) sum2 ++;
        if (i %2==0 && one >two + sum ) {mn = min (mn , i+1 ) ;}
        if (i %2 && two >one + sum ) {mn = min (mn , i+1 ) ;}
        if (i %2==0 && one+ sum2 <two ) {mn = min (mn , i+1 ) ;}
        if (i %2 && two + sum2 <one ) {mn = min (mn , i+1 ) ;}
    }
    cout << mn << endl;
}   

int32_t main(){
   #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
   #endif
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; int test_case=1;
    cin >> test_case ;
    while (test_case--)  solve() ;

}