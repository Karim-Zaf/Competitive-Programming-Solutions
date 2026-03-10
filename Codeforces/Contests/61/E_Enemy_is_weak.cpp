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

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

const ll N = 1e7+5 , MOD =1e9+7, Q =2e5+3 ;

void solve (){
    int n ,x ;
    ll res = 0 ; 
    indexed_set Itree1, Itree2 ;
    cin >> n ; 
    vector <int> v (n); 
    for (int i= 0 ;i<n ; i++) {
        cin >> v[i] ;
        Itree1 .insert(v[i]) ; 
    } 
    reverse(all(v)) ; 
    for (int i= 0 ;i<n ; i++){
        Itree1.erase(v[i]);
        v[i]=v[i] ; 
        ll nb1 = Itree2.order_of_key(v[i]) ;
        ll nb2 = Itree1.size() - Itree1.order_of_key(v[i]);
        res += nb1 * nb2 ; 
        Itree2.insert(v[i]);
    }
    cout << res <<endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif 
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; ll test_case=1;     
    // cin >> test_case ; 
    while (test_case--)  solve() ;
}