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
    int a , b , k , cnt =0, cntones=0;
    cin >> a >> b>> k ;
    string one="" , two="" ;
    for (int i= 0 ; i<a+b ; i++)one += '0' , two += '0' ;
    if (k==0){
        for (int i= 0; i<b; i++)one[i]=two[i]='1' ;
        cout << "YES\n" << one << "\n" << two << "\n" ;
        return ;
    }
    if (k>= a+b){cout << "NO\n";return;}
    two[0]= one[k]= '1' ;
    for (int i= a+b-1 ; i>=0 ; i--) {
        if (one[i]=='0'&&two[i]=='0'&& cntones<b-1){
            one[i]= two[i]= '1' ;
           cntones++ ;
        }
    }


    for (auto c : one ) cnt +=(c=='0');
    if (one.back()=='0'||two.back()=='0'||cnt!=a) {cout <<"NO\n";return;}
    reverse(all(one)) ;
    reverse(all(two)) ;

    cout << "YES\n" << one << "\n" << two << "\n" ;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}