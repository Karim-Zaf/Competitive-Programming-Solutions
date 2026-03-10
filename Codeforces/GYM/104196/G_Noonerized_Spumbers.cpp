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
 
const ll N =2e5+ 8 ,  MOD =1e9+7, mod=1e9+7, INF = 1e18;
 
void solve() {
    int x , y , z ;
    char one , two ;
    cin >> x >> one >> y >>two >> z ;
    string a = to_string(x) ;
    string b = to_string(y) ;
    string c = to_string(z) ;
    auto stoiiiiiii=[](string s){
        int k =1, res= 0 ;
        for (int i= s.size()-1 ; i>=0;i--){
            res+=(s[i]-'0')*k ;
            k*=10;
        }
        return res ;
    };
    auto ok =[&](string a , string b , int i , int j , int &nwa , int& nwb ) {
        string prefa="" , prefb="" , suffa="", suffb="";
        for (int k = 0 ; k<i ; k++)prefa+= a[k] ;
        for (int k = i ; k<a.size() ; k++)suffa+= a[k] ;
        for (int k = 0 ; k<j ; k++)prefb+= b[k] ;
        for (int k = j ; k<b.size() ; k++)suffb+= b[k] ;
        suffa = prefb + suffa ;
        suffb= prefa + suffb ;
 
        nwa = stoiiiiiii(suffa);
        nwb = stoiiiiiii(suffb);
    };
    for (int i= 1 ; i<= 32 ;i++ ){
        for (int j= 1 ; j<=32 ; j++) {
            if (i < a.size() && j < b.size()) {
                int nwa, nwb;
                ok(a, b, i, j, nwa, nwb);
                if (one == '+' && nwa + nwb == z) {
                    cout << nwa << " + " << nwb << " = " << z << endl;
                    return;
                }
                if (one == '*' && nwa * nwb == z) {
                    cout << nwa << " * " << nwb << " = " << z << endl;
                    return;
                }
            }
            if (i < a.size() && j < c.size()) {
                int nwa, nwc;
                ok(a, c, i, j, nwa, nwc);
                if (one == '+' && nwa + y == nwc) {
                    cout << nwa << " + " << y << " = " << nwc << endl;
                    return;
                }
                if (one == '*' && nwa * y == nwc) {
                    cout << nwa << " * " << y << " = " << nwc << endl;
                    return;
                }
            }
            if (i < b.size() && j < c.size()) {
                int nwb, nwc;
                ok(b, c, i, j, nwb, nwc);
                if (one == '+' && x + nwb == nwc) {
                    cout << x << " + " << nwb << " = " << nwc << endl;
                    return;
                }
                if (one == '*' && x * nwb == nwc) {
                    cout << x << " * " << nwb << " = " << nwc << endl;
                    return;
                }
            }
        }
    }
}
 
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
//    cin >> test_case ;
    while (test_case--)  solve() ;
}