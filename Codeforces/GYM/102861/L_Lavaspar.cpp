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
#define pi pair<ll,ll>
#define vi vector<ll>
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define non cout<<"-1\n";
#define F first
#define S second
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define INF (ll)(1e18)
template<typename T>void dbg(const T&x){for(auto&i:x)cout<<i<<' ';cout<<'\n';}

const ll N = 1e8 + 1 , MOD =1e9+7, mod=1e9+7, Q =2e5+4 ;
int n , m , k, res = 0 , ver [22][42][42]  ;
vector <string> anagrammes ; 
char t[42][42];

map <char , vector <pair <int,int>>> mp ;

void verif (char deb , string s , int curr ){
    for (auto x: mp[deb]){

        string verif = "";
        for (int i= x.F ;  i<x.F+s.size() && i < n ; i++ )
            verif += t[i][x.S];
        sort (all(verif));
        if (verif == s) {
            for (int i= x.F ; i<x.F+s.size()&&  i < n ; i++ ){
                ver[curr][i][x.S]=1 ;
                // cout << curr << " " << i << " " << x.S << endl;
            }
        }

        verif = "";
        for (int j= x.S ; j<x.S + s.size() && j < m ; j++ )
            verif += t[x.F][j];
        sort (all(verif));
        if (verif == s) {
            for (int j= x.S ; j<x.S + s.size() && j < m ; j++ )
                ver[curr][x.F][j]=1 ;
        }

        verif = "";
        for (int e = 0 ; e< s.size() && x.F + e <n  && x.S + e <m ; e++)
            verif += t[x.F+e][x.S+e];
        sort (all(verif));
        if (verif == s) {
            for (int e = 0 ; e< s.size() && x.F + e <n  && x.S + e <m ; e++)
                ver[curr][x.F+e][x.S+e]=1;
        }

        verif = "";
        for (int e = 0 ; e< s.size() && x.F + e <n  && x.S - e >=0 ; e++)
            verif += t[x.F+e][x.S-e];
        sort (all(verif));
        if (verif == s) {
            for (int e = 0 ; e< s.size() && x.F + e <n  && x.S - e >=0 ; e++)
                ver[curr][x.F+e][x.S-e]=1;
        }
    }
}

void solve(){
    cin >> n >> m ; 
    for (int i=0 ;i<n ;i++ ) 
        for (int j= 0 ;j <m ; j++){
            cin >> t[i][j];
            mp[t[i][j]].pb(make_pair(i,j));
        }
    memset(ver,0,sizeof(ver));
    cin >> k ; 
    for (int i= 0 ;i< k ;i++){
        string h ;
        cin >> h ;
        sort (all(h));
        anagrammes .pb(h);
    }
    for (int i = 0 ;i<k ;i++){
        for (auto c : anagrammes[i])
            verif (c,anagrammes[i],i);
    }
    for (int i= 0 ;i<n ;i++)
        for (int j= 0 ;j<m ;j++){
            int cnt =0;
            for (int e = 0 ;e<k ;e++){
                cnt += ver[e][i][j];
            }
            if (cnt>= 2) res ++;
        }
    // for (int e = 0 ;e<k ;e++){
    //     for (int i= 0 ;i<n ;i++){
    //         for (int j= 0 ;j<m ;j++)
    //             cout << ver[e][i][j] << " ";
    //         cout << endl;
    //     }   
    //     cout << endl << endl;
    // }
    cout << res << endl ;
}

int32_t main(){
   #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
   #endif
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; int test_case=1;
    // cin >> test_case ;
    while (test_case--)  solve() ;

}