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

const int  N=1e5+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;

int n , q;
int lazy [4*N][20], Tree[4*N][20] ,v[N];

void unlazy(int id,int ns , int ne){
    int l = 2*id +1 , r = 2*id +2 ;
    for (int i= 0 ; i<20; i++)
        if (lazy[id][i]){
            Tree[id][i]= (ne-ns+1) -Tree[id][i];
            if (l<4*N)lazy[l][i]^=1;
            if (r<4*N)lazy[r][i]^=1;
            lazy[id][i]=0;
        }
}

void update (int qs , int qe , int val , int ns=1 , int ne=n , int id =0){
    unlazy(id,ns,ne);
    if (qs >ne|| qe <ns) return ;
    if (qs <= ns && ne <= qe ){
        for (int i= 0 ;i<20; i++) if ((1ll<<i)&val) lazy[id][i]^=1 ;
        unlazy(id,ns,ne);
        return ;
    }
    int l = 2*id +1 , r = 2*id +2 , md = ns + (ne-ns)/2 ;
    update (qs , qe , val , ns , md, l);update (qs ,qe, val , md+1 , ne ,r);
    for (int i= 0; i<20; i++) Tree[id][i]= Tree[l][i]+ Tree[r][i];
}

int query (int qs ,int qe,int bit , int ns=1 , int ne=n , int id =0){
    unlazy(id,ns,ne);
    if (qs >ne|| qe <ns) return 0;
    if (qs <= ns && ne <= qe ) return Tree[id][bit];

    int l = 2*id +1 , r = 2*id +2 , md = ns + (ne-ns)/2 ;
    return query(qs , qe , bit,ns , md, l)+query(qs ,qe, bit,md+1 , ne ,r);
}


void Solve() {
    cin >> n ;
    for (int i= 1;i<=n;i++) {
        cin >>v[i];
        update (i,i,v[i]);
    }
    cin >> q ;
    while (q--){
        int x , l , r , val,sum=0 ; cin>> x ;
        if (x==2){
            cin >> l >> r >> val ;
            update (l,r,val);
        }else {
            cin >> l >> r ;
            for (int i= 0; i<20; i++)
                sum += (1ll<<i)*query(l,r,i);
            cout << sum <<endl;
        }
    }

}

int32_t main(){
     #ifndef ONLINE_JUDGE
         freopen("/home/karim/Documents/Setup_Karim_Codeforces_november_14/input.txt","r",stdin);
         freopen("/home/karim/Documents/Setup_Karim_Codeforces_november_14/output.txt","w",stdout);
     #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case ;
    while (Test_case--) Solve();
}