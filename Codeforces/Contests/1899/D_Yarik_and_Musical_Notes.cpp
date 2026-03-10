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

const int  N=2e5+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;


void Solve(){
    int n , res= 0;
    cin >> n ;
    vector <int> v(n+1)  ;
    map <int,vector<pair<int,int>> > mp;
    for (int i= 0 ; i<n  ;i++){
        cin >> v[i] ;
        int cnt = 0 , e = v[i];
        while (e%2==0) {
            e/=2 ;
            cnt ++ ;
        }
        mp[e].pb({v[i],cnt});
    }

    for (auto [val, vect ]  : mp ){
        int sz = vect.size() ;
        map <int,int> mp2 ;
        for (int i= 0 ; i< sz ; i++){
                mp2[vect[i].F -vect[i].S]++;
        }
        for (auto x: mp2) res += x.S *(x.S -1 )/2 ;

    }
    cout << res << endl;
}


int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("/home/karim/Documents/Setup_Karim_Codeforces_november_14/input.txt","r",stdin);
        freopen("/home/karim/Documents/Setup_Karim_Codeforces_november_14/output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case ;
    while (Test_case--) Solve();
}