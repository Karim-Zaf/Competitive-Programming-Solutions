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
 
void Solve() {
    int n , q ;
    cin >> n >> q ;
    vector<int> t(8);
    for (int i= 0 ; i<8; i++)t[i]=i;
    auto convert =[&](pair<int,int>p )-> int{
          return (p.F-1)*n + p.S;
    };
    while (q--){
        char c;cin >> c ;
        if (c=='r'){
            cin>> c;
            if (c=='b'){
                swap(t[0],t[1]), swap(t[2],t[3]);
                swap(t[4],t[5]), swap(t[6],t[7]);
            }
            if (c=='d'){
                swap(t[0],t[6]), swap(t[1],t[7]);
                swap(t[2],t[4]), swap(t[3],t[5]);
            }
            if (c=='a'){
                swap(t[0],t[2]), swap(t[4],t[1]);
                swap(t[3],t[6]), swap(t[5],t[7]);
            }
            if (c=='c'){
                swap(t[3],t[1]), swap(t[0],t[5]);
                swap(t[2],t[7]), swap(t[6],t[4]);
            }
            kar (t);
        }else {
            int x, y ,nwx,nwy , mn = INF;
            cin >> x >> y ;
            pair<int,int> v[8];
            v[0]=make_pair(x,y);
            int curr = convert ({x, y});
            v[1]=make_pair(x,abs(n-y+1));
            v[2]=make_pair(abs(n-x+1),y);
            v[3]=make_pair(abs(n-x+1),abs(n-y+1));
            v[4]=make_pair(y,x);
            v[5]=make_pair(abs(n-y+1),x);
            v[6]=make_pair(y,abs(n-x+1));
            v[7]=make_pair(abs(n-y+1),abs(n-x+1));
 
            for (int i= 0 ; i<8; i++){
                if (convert(v[i])<=mn){
                    nwx = x;
                    nwy = y;
                }
            }
 
            v[0]=make_pair(x,y);
            v[1]=make_pair(x,abs(n-y+1));
            v[6]=make_pair(abs(n-x+1),y);
            v[7]=make_pair(abs(n-x+1),abs(n-y+1));
            v[2]=make_pair(y,x);
            v[3]=make_pair(y,abs(n-x+1));
            v[4]=make_pair(abs(n-y+1),x);
            v[5]=make_pair(abs(n-y+1),abs(n-x+1));
 
            for (int i=0 ; i<=7 ; i++){
                if (curr == convert(v[i])){
                    cout << convert(v[t[i]])<<endl;
                    break;
                }
            }
 
        }
    }
 
}
 
int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}