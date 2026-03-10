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

const int N=3e5+30,mod=1e9+7,MOD=mod,INF=1e18+10;

int n , m , x;
int work (int curr, int dharba, int indx){
    int imin = curr +dharba;
    imin -- ;
    imin %= n;
    imin ++ ;

    int isar= curr -dharba;
    isar --;
    isar +=n ;
    isar %= n ;
    isar++;
    if (indx==0)return isar ;
    else return imin ;
}

void Solve() {
    cin >> n >> m >> x;
    set<int> s ;
    s.insert(x);
    for (int i=1; i<=m ;i++){
        int dharba;
        char c ;
        cin >> dharba>> c;
        set<int> nw_s;
        for (auto x: s){
            if (c == '0')
                nw_s.insert(work(x,dharba,1));
            else if (c=='1')
                nw_s.insert(work(x,dharba,0));
            else {
                nw_s.insert(work(x,dharba,1));
                nw_s.insert(work(x,dharba,0));
            }
        }
        s = nw_s ;
    }

    cout << s.size() << endl;
    for (auto x: s)cout << x << " "; cout << endl;

}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0),cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}