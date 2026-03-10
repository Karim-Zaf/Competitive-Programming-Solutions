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

const int  N=2e4+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;


void Solve() {

    int a, b , c ;
    cin >> a >> b >> c ;
    auto cnt =[&] (int one ,int two , int three){
        return abs(a-one)+ abs(b-two) + abs (c-three) ;
    };
    int ansa = 1, ansb= 1, ansc=1 ;
    int ans = cnt (ansa,ansb,ansc);

    for (int i= 1 ; i<N ; i++){
        for (int j= i ; j<N ; j+= i){
            for (int k = j ; k<N ; k+=j){
                int curr = cnt (i,j,k) ;
                if (curr<= ans){
                    ans = curr ;
                    ansa = i , ansb =j , ansc = k ;
                }
            }
        }
    }

    cout<< ans << endl;
    cout << ansa << " " << ansb << " " << ansc << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}