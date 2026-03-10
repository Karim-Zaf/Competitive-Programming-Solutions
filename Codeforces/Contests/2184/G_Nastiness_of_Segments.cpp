/*  ██╗  ██╗ █████╗ ██╗██████╗ ███╗   ███╗        ███████╗ █████╗ ███████╗
    ██║ ██╔╝██╔══██╗██║██╔══██╗████╗ ████║        ╚══███╔╝██╔══██╗██╔════╝
    █████╔╝ ███████║██║██████╔╝██╔████╔██║          ███╔╝ ███████║█████╗
    ██╔═██╗ ██╔══██║██║██╔══██╗██║╚██╔╝██║         ███╔╝  ██╔══██║██╔══╝
    ██║  ██╗██║  ██║██║██║  ██║██║ ╚═╝ ██║███████╗███████╗██║  ██║██║
    ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝     */
#include <bits/stdc++.h>
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
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int ll
#define endl '\n'

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;


template<class T> struct Seg {  /*CHANGE THE ID YA KARIM !!*/
    const T ID = INF; int n; vector<T> seg;
    T merge(T a, T b){ return  min ( a , b )  ; } 
    Seg(int _n): n(_n), seg(2*n, ID){} 
    void pull(int p){ seg[p] = merge(seg[2 * p],seg[2*p + 1]); }
    void upd(int p, T val){ seg[p+=n] = val; for(p/=2 ; p ; p/=2) pull(p); }
    T query(int l, int r) { T ra= ID, rb= ID; for(l+= n, r+= n + 1 ; l<r ; l/=2,r/=2){
            if(l&1) ra = merge(ra,seg[l++]); if(r&1) rb = merge(seg[--r],rb);
        }return merge(ra,rb);
    } void print(int i=-1){
        while(++i < n) cout<<(i==0?"sg : ":"")<<query(i,i)<<(i==n-1?"\n":" ");}
};

void Solve(){
    int n, m;
    cin >> n >> m;

    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];

    Seg<int> sg(n + 1);
    for (int i = 1; i <= n; i++) sg.upd(i, v[i]);

    while (m--){
        int x;
        cin >> x;
        if (x == 1){
            int i;
            cin >> i >> x;
            v[i] = x;
            sg.upd(i, v[i]);
        }
        else{
            int l, r;
            cin >> l >> r;

            int lef = 0, righ = r - l, pos = -1;
            while (lef <= righ){
                int mid = (lef + righ) / 2;
                int curr_pos = l + mid;
                if (sg.query(l, curr_pos) <= mid){
                    righ = mid - 1;
                    if (sg.query(l, curr_pos) == mid)
                        pos = curr_pos;
                }
                else lef = mid + 1;
            }

            if (pos != -1) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
