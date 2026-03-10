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

const int  N=2e5+8,MOD=998244353,mod=998244353,INF=1e18;



void Solve(){
    int one =0 ,zero = 0,cnt=0;
    string ch ;
    cin >> ch ;
    ch=ch+ 'S';
    int n =ch.size() ;
    vector <int> v, fact (n+5);
    fact[0]=1 ;
    char prev='x';
    for (int i= 1 ;i<=n+4;i++)fact[i]= (i*fact[i-1])%mod ;
    int i= 0 ;
    while (i<n){
        int interm =0;
        kar (prev);
        if (ch[i]==prev){
            cnt ++ ;
        }else {
            if(i)v.pb(cnt);
            cnt =1 ;
            prev = ch[i] ;
        }
        i++;
    }
    int res2=1 , res =0;

    for (int i= 0 ;i<v.size();i++ ){
        res += v[i]-1 ; 
        res2 *=v[i];
        res2%=mod ;
    }
    cout << res <<" " << (res2*fact[res])%mod<< endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0); int Test_case=1;
    cin >> Test_case ;
    while(Test_case--)Solve();
}