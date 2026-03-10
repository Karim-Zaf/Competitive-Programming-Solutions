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
 
const int N=1e5+8,MOD=1e9+7,mod=1e9+7,INF=1e18;
 
string sum(string a , string b){
    reverse (all(a)) ;
    reverse (all(b)) ;
    string res = "" ;
    int ihtifadh = 0 ;
    while (a.size() <b.size())a+= "0";
    while (b.size() <a.size())b+= "0";
    for (int i= 0 ; i<a.size() ; i++){
        int curr = a[i]-'0'+b[i]-'0' + ihtifadh ;
        ihtifadh = curr /10;
        res += char ( curr%10 + '0');
    }
 
    if (ihtifadh !=0) res +=char (ihtifadh+'0') ;
    reverse (all(res));
    return res ;
}
 
 
 
void Solve() {
    int  n , k= 0;
    cin >> n ;
 
    vector <string> v(n);
    for (auto &x :v) cin >> x ;
    string j = "1" ;
 
    while (true){
        int i= 0;
 
        vector <string> nw_v ;
        while (i<v.size()){
            if (i<v.size()-1 && v[i]==v[i+1]&&v[i]==j)
                nw_v.pb(sum(v[i], v[i++]));
            else nw_v.pb(v[i]);
            i++;
        }
        v = nw_v ;
        nw_v.clear();
        if(v.size()==1) break;
        for (auto x: v) if (x !=j) nw_v.pb(x);
        v = nw_v ;
        if(v.size()==1) break;
        j= sum (j,j);
    }
    cout << v.back() << endl;
}
 
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--)Solve();
}