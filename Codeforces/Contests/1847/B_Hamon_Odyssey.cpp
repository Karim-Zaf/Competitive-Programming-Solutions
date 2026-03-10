/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
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
#define endl '\n'
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define nop cout<<"-1"<<endl;
#define int ll

const ll N = 1e5 + 8 , MOD =1e9+7, mod=1e9+7, INF = 1e18 ;

void solve(){
    int n , ad= -1 ;
    cin >> n ;
    vector <int> v(n+1) , suff (n+1) ,nw;
    for (int i= 0;i<n ;i++){
        cin >> v[i];
        if (ad == -1) ad = v[i];
        else ad &= v[i] ;
    }
    suff[n-1]= v[n-1];
    for (int i= n-2 ; i>=0 ; i--)
        suff[i] = v[i] & suff[i+1];

    int andd = -1 , cnt=0 , sum = 0;
    for (int i= 0 ;i<n ;i++){
        if (andd ==-1) andd = v[i];
        else andd &= v[i] ;
        if ( sum +andd + suff[i+1]<= ad){
            sum  += andd;
            andd = -1;
            cnt ++;
        }
    }
    cout << cnt << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
    cin >> test_case ;
    while (test_case--)  solve() ;
}

// Failure gives you two choices: You stay down or You get up ;)