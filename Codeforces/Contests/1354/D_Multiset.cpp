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

template<class T>struct BIT {
	int N; vector<T> data;
	void init(int _N) { N = _N; data.resize(N); }
	void add(int p, T x) { for (++p;p<=N;p+=p&-p) data[p-1] += x; }
	T sum(int l, int r) { return sum(r+1)-sum(l); }
	T sum(int r) { T s = 0; for(;r;r-=r&-r)s+=data[r-1]; return s; }
};

void Solve() {
    int n ,q ,x ;
    cin >> n >> q ;
    BIT<int> sg;
    sg.init(n+4) ;
    vector<int> mp(n+5);
    for (int i=1 ; i<=n ;i++){
        cin >> x;
        sg.add(x,1);
    }
    while (q--){
        cin >> x;
        if (x>=0){sg.add(x,1);continue;}
        int l = 0 , r = n , ans =-1;
        while (l<=r){
            int md = l + (r-l)/2 ;
            if (sg.sum(0,md)>=(-x)){
                ans = md ;
                r = md -1 ;
            }else l = md+1 ;
        }
        sg.add(ans,-1);
    }

    for (int i=0 ; i<=n ;i++){
        if (sg.sum(i,i)){cout << i << endl ; return ;}
    }
    cout << 0 << endl;

}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}