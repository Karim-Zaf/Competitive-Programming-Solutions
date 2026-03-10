/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#ifndef ONLINE_JUDGE
#include "debug.cpp"
#else
#define kar(...)
#endif
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define int ll
#define endl '\n'

const int  N=5e6+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;


void Solve() {
    int n , l = 1 , prd = 1, r = 1;
    cin >> n ;
    vector <int> v(n+3) , pref(n+4), last ;
    
    for (int i= 1 ; i<=n ;i++){
        cin >> v[i] ;
        pref[i]= pref[i-1] + v[i] ;
    }
    
    int sum = pref[n],first= 1 , lst = n;
    
    for (int i= 1; i<=n ; i++){
        prd *= v[i] ;
        if (prd> 1e15||prd<=0){
            while (v[first]==1)first++;
            while (v[lst]==1)lst--;
            cout << first << " " << lst << endl;
            return ;
        }
    }
    
    prd = sum;
    
    for (int i=1 ; i<=n ;i++){
        if (v[i]!=1) last.pb(i) ;
        for (int j= last.size()-1 , p = 1; j>= max(0ll,(int)last.size()-60); j--){
            p *= v[last[j]];
            int pr = pref[last[j]-1] , suff = sum -pref[i] ;
            if (p+ pr + suff >= prd ){
                prd = p + pr + suff ;
                l = last[j] , r = i ;
            }
        }
    }
    
    cout << l<< " " << r << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}