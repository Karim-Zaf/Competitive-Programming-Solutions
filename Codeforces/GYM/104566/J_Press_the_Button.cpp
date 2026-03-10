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
 
int lcm (int a, int b) {
    return a*b/__gcd (a,b);
}
 
int a,b,c,d,v,t;
vector<int> work(){
    vector<int> vis (c), res, fin;
    vector<int> cycle ;
    cycle.pb(0) ;
    vis[0]=1 ;
    res.pb(0);
    while (true){
        int curr = cycle.back()+a ;
        int kabli = curr/c*c  ;
        int currwraya = curr - a ;
        int kbalkabli = currwraya /c*c +c;
        int ins = res.back();
        ins+=(abs(curr-kabli)<=v);
        ins+=(abs(currwraya - kbalkabli)<=v);
        res.pb(ins);
        curr%= c ;
        cycle.pb(curr);
        if (vis[curr])break;
        vis[curr]=1 ;
    }
    return res;
}
 
void Solve() {
    cin >> a >> b >> c >> d >> v >> t ;
 
    int ans = 0 ,cnt= 0;
 
    vector<int> res1 = work();
    swap (a,c);
    swap (b,d);
    vector<int> res2= work();
 
    ans += (t/a+1)*(b-1) ;
    ans += (t/c+1)*(d-1) ;
 
    if (a<=v||c<=v) ans += t/a + t/c +1 ;//not 2 cause first time
    else  {
        int indx = t%lcm(a,c) ;
        if (indx/c*c>=indx/a*a)ans += res1[indx/c];
        else ans += res2[indx / a] ;
 
        int nb = t/ lcm(a,c);
        assert (res1.back()==res2.back());
        ans += nb*res1.back()+1;
    }
    cout << ans << endl;
}
 
int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}