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

const int  N=3e5+30,MOD=998244353,mod=998244353,INF=1e18+10;


int add (int x , int y ){return ((x%mod+y%mod)+mod)%mod; }
int mult (int x , int y ){ return x%mod*y%mod; }
map <int,int> mp3 [N];
int fact[N] ;
void Solve() {
    fact[0]=1 ;
    for (int i= 1; i<N ; i++) fact[i]= mult (i,fact[i-1]);
    map <int,int> mp1 , mp2 , mx , mn;
    int sum1 = 1, sum2= 1 , sum3=1 ,  n , prev = -INF;
    cin >>n ;
    vector <pair<int,int>> vp(n) ;
    for (int i = 0 ; i<n ;i++){
        cin >> vp[i].F >> vp[i].S ;
        mp1[vp[i].F] ++ ;
        mp2[vp[i].S] ++ ;
        mx [vp[i].F] = max(mx[vp[i].F], vp[i].S);
        if (!mn[vp[i].F])mn[vp[i].F]=INF ;
        mn [vp[i].F] = min(mn[vp[i].F], vp[i].S);
        mp3[vp[i].F][vp[i].S]++;
    }

    for (auto x: mn) {
        if (x.S<prev) sum3=0 ;
        prev = mx[x.F] ;
    }
    for (auto x: mp1) {
        sum1 =mult (sum1, fact[x.S]);
        for (auto x2 : mp3[x.F])
            sum3 = mult (sum3, fact[x2.S]) ;
    }
    for (auto x: mp2) sum2 =mult (sum2 , fact[x.S]);
    cout << add (fact[n],- add(sum1,add (sum2,-sum3))) << endl;
}



int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}