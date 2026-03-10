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


int Tree[26][4*N] , upd[26][4*N],a[N],n,q, lazy[26][4*N] ;
string s ;

void unlazy(int c, int id,int ns , int ne){
    if (upd[c][id]==0) return;
    int l = 2*id +1 , r = 2*id +2 ;
    Tree[c][id]= (ne-ns+1) * lazy[c][id] ;
    upd[c][id]=0;
    if (r>=4*N) return;
    lazy[c][l]= lazy[c][r] = lazy[c][id] ;
    upd[c][l]= upd[c][r]= 1 ;
}

void update (int qs , int qe , int c, int val , int ns=0 , int ne=n-1 , int id =0){
    unlazy(c,id,ns,ne);
    if (qs >ne|| qe <ns||qs>qe) return ;
    if (qs <= ns && ne <= qe ){
        upd[c][id]=1; lazy[c][id]=val;
        unlazy(c,id,ns,ne);
        return ;
    }
    int l = 2*id +1 , r = 2*id +2 , md = ns + (ne-ns)/2 ;
    update (qs , qe ,c, val , ns , md, l);
    update (qs ,qe, c,val , md+1 , ne ,r);
    Tree[c][id]=Tree[c][l]+Tree[c][r];
}

int query (int qs , int qe , int c ,int ns = 0 , int ne =n-1  , int id = 0){
    unlazy(c, id,ns,ne);
    if (qs >ne || qe<ns||qs> qe)return 0;
    if (qs <= ns && ne <= qe) return Tree[c][id] ;
    int l = 2*id +1 , r = 2*id +2 , md = ns + (ne-ns)/2 ;
    return query(qs,qe,c,ns,md,l)+query(qs,qe,c,md+1,ne,r);
}


void Solve() {
    cin >> n >> q >> s;
    for (int i=0 ; i<n; i++)
        update(i,i, s[i]-'a',1);

    while(q--){
        int x , l, r   ; cin >>l >> r >> x ;
        l--, r--;
        if (x==1){
            int lef = l ,lll = l;
            for (int i= 0 ; i<26; i++){
                int cnt = query (lll,r,i);
                lef += cnt ;
                update (lll,r,i,0);
                update (l,lef-1,i,1);
                l = lef ;
            }
        }else{
            int lef = l ,lll=l;
            for (int i= 25 ; i>=0; i--){
                int cnt = query (lll,r,i);
                lef += cnt ;
                update (lll,r,i,0);
                update (l,lef-1,i,1);
                l = lef ;
            }
        }
    }
    for (int k= 0 ;k<n ; k++)
        for (int j= 0 ; j<26 ;j ++)
            if (query (k,k,j)){
                cout << char (j+'a') ;
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