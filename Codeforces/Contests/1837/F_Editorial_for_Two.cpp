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

const ll N = 2e5+5 , MOD =1e9+7, Q =2e5+3 ;
int n , k ;
vector <int> v ;

bool verif (long long x ){
    long long sum = 0 ;
    vector <int> left (n,0) , right(n,0);
    priority_queue <int> pq,pq2 ;
    for (int i = 0;i<n ;i++){
        pq.push(v[i]) ;
        sum += v[i] ;
        while( sum >x ){
            sum -= pq.top();
            pq.pop() ;
        }
        left[i] = pq.size();
    }
    sum = 0;
    for (int i = n-1;i>=0 ;i--){
        pq2.push(v[i]) ;
        sum += v[i] ;
        while( sum >x ){
            sum -= pq2.top();
            pq2.pop() ;
        }
        right[i] = pq2.size();
    }
    if (left[0]>=k) return true;
    for (int i= 1;i<n ;i++)
        if (left[i-1]+ right[i]>=k) 
            return true ;
    return false ; 
}

void solve (){
    long long mid , l = 0 , r = INF , ans; 
    cin >> n>> k ; 
    v.clear();
    v.resize(n);
    for(int i = 0 ;i<n ; i++) cin >> v[i] ;
    while ( l < r ){
        mid = l + (r-l)/2 ; 
        if (verif(mid))
            r= mid  ;
        else 
            l= mid +1 ;
    }
    cout << r <<endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif  
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; int test_case=1;     
    cin >> test_case ; 
    while (test_case--)  solve() ;
}