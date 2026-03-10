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
#define pi pair<long long,long long>
#define vi vector<long long>
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define non cout<<"-1\n";
#define F first
#define S second
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define INF (ll)(1e18)
template<typename T>void dbg(const T&x){for(auto&i:x)cout<<i<<' ';cout<<'\n';}

const ll N = 2e5+5 , MOD =1e9+7, mod=1e9+7, Q =2e5+3 ;



void solve (){
    int n ; 
    cin >> n; 
    vi v(n) ;
    for (int i = 0 ;i<n ;i++ ) cin >> v[i];
    int l = 0 , r= n-1 , flag = 0 , sum1 = 0 , sum2 =0;
    while(l<=r){
        if (flag%2 == 0 ){
            if (v[l]>v[r]){
                sum1 += v[l];
                l++;
            }
            else {
                sum1+= v[r];
                r-- ;
            }
        }else {
            if (v[l]>v[r]){
                sum2 += v[l];
                l++;
            }
            else {
                sum2+= v[r];
                r-- ;
            }
        }
        flag++;
    }
    cout << sum1 << " " << sum2 << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif  
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; int test_case=1;     
    // cin >> test_case ; 
    while (test_case--)  solve() ;
}