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
#define long double double
const int  N=5e6+8,MOD=1e9+7,mod=1e9+7,INF=1e17;

void Solve(){
    int n , m , k, sum = 0  ;
    cin >> n >> m >> k ;
    multiset <int> a, b ;
    vector <int> res(9) ;
    for (int i= 0 ;i<n;i++){
        int x ; cin >> x ;
        a.insert(x) ;
        sum += x ;
    } for (int i= 0 ;i<m;i++){
        int x ; cin >> x ;
        b.insert(x) ;
    }
    for (int i= 1;i<=8; i++){
        if (i%2){
            int lekhor = *prev(b.end());
            int ena = *a.begin();
            if (lekhor -ena >=0){
                sum+=lekhor-ena ;
                b.erase(b.find(lekhor));
                a.erase(a.find(ena));
                a.insert(lekhor) ;
                b.insert(ena);
            }
        }
        else {
            int lekhor = *prev(a.end());
            int ena = *b.begin();
            if (lekhor -ena >=0){
                sum-=lekhor-ena ;
                b.erase(b.find(ena));
                a.erase(a.find(lekhor));
                a.insert(ena) ;
                b.insert(lekhor);
            }
        }
        res[i]=  sum ;
    }
    if (k<=8) cout << res[k]<< endl;
    else if (k%2) cout << res [7] << endl;
    else cout << res [8] << endl;
//    cout << sum << endl;
}


int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0); int Test_case=1;
    cin >> Test_case ;
    while(Test_case--)Solve();
}