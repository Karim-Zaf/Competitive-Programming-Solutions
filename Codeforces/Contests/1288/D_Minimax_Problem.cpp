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
#define int ll

const ll N = 2e5+ 8 ,  MOD =1e9+7, mod=1e9+7, INF = 1e10 ;

void solve(){
    int n , m , one = -1 , two = -1;
    cin >> n>> m ;
    vector <vector <int>> t (n , vector <int> (m));
    vector <pair <int,int>> mp ((1<<m)) ;
    for (int i= 0 ;i<n ; i++)
        for (int j= 0 ; j<m ; j++ )
            cin >> t[i][j];
    for (int j= 0 ; j< (1<<m) ; j++) mp[j]= {-1,-1};
    for (int i= 0 ; i< n; i++){
        for (int j= 0 ; j< (1<<m) ; j++){
            int mn = INF ;
            for (int k = 0 ; k<m ;k ++ )
                if ( j& (1<<k))
                    mn = min (mn , t[i][k]);
            if (mn > mp[j].F) mp[j] = {mn,i};
        }
    }
    int l = 0 , r = 1e9+2 ; r++;
    while (l<= r){
        int md = l + (r-l)/2 , ok = 0  ;
        for (int i= 0 ; i<n ;i++){
            int masque = 0 ;
            for (int j =0 ;j<m ;j++)
                if (t[i][j] < md)
                    masque += (1<< j);
            if ( md <= mp[masque].F ) {
                one = i +1 ;
                two =mp[masque].S +1 ;
                ok = 1 ;
                break;
            }
        }
        if (ok) l = md +1 ;
        else r = md -1 ;
    }
    cout << one << " " << two << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
//    cin >> test_case ;
    while (test_case--)  solve() ;
}

// Failure gives you two choices: You stay down or You get up ;)