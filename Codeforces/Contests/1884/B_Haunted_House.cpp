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

const int  N=2e5+30,MOD=1e9+7,mod=1e9+7,INF=1e18+6;

void Solve() {
    int n , one=0 , two ;
    string s ;
    cin >> n >> s;
    reverse (all(s));
    vector <int> res (n+3,-1);
    while(s[one]!='1'&& one <n)one++;
    two = one+1 ;
    for (int i= 1 ;i<=n ;i++){
        if (i<=one){
            res[i]=0;
            continue;
        }else res[i]=max(0ll,res[i-1]);
        for (;two<n && one<i;two++){
            if (s[two]=='0')
                res[i]+= (two-one);
            one+=(s[two]=='0');
        }
        if (one!=i) res[i]=-1 ;
    }
    for (int i= 1  ;i<=n ;i++ ) cout <<res[i]<< " " ; cout << endl;

}


int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}