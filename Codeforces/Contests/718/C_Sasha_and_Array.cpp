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

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

const int N_mat = 2;

struct Matrix {
    long long a[N_mat][N_mat];

    Matrix() {
        for (int i = 0; i < N_mat; i++)
            for (int j = 0; j < N_mat; j++)
                a[i][j] = 0;
    }

    Matrix operator*(Matrix other) {
        Matrix product;
        for (int i = 0; i < N_mat; i++)
            for (int j = 0; j < N_mat; j++)
                for (int k = 0; k < N_mat; k++) {
                    product.a[i][j] += (a[i][k] * other.a[k][j]) % mod;
                    product.a[i][j] %= mod;
                }
        return product;
    }

    Matrix operator+(Matrix other) {
        Matrix sum;
        for (int i = 0; i < N_mat; i++)
            for (int j = 0; j < N_mat; j++)
                sum.a[i][j] = (a[i][j] + other.a[i][j]) % mod;
        return sum;
    }
};

void print(Matrix s) {
    for (int i = 0; i < N_mat; i++) {
        for (int j = 0; j < N_mat; j++)
            cout << s.a[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}


Matrix expo_power(Matrix a, long long k) {
    Matrix ret;
    for (int i = 0; i < N_mat; i++) ret.a[i][i] = 1; //identity
    while (k) {
        if (k % 2)
            ret = ret * a;
        a = a * a;
        k /= 2;
    }
    return ret;
}

/*----------------------------------------Lazy--------------------------------------------*/

Matrix fib;
Matrix Tree[4 * N], lazy[4 * N], a[N];
Matrix m;
int n;
int upd[4 * N];

int merge(int a, int b) { return (a + b)%mod; }

void unlazy(int id) {
    if (upd[id] == 0) return;
    int l = 2 * id + 1, r = 2 * id + 2;
    Tree[id] = Tree[id] * lazy[id];
    lazy[l] = lazy[l] * lazy[id], lazy[r] = lazy[r] * lazy[id];
    upd[l] = upd[r] = 1, upd[id] = 0;
    lazy[id] = m;
}

void update(int qs, int qe, Matrix val, int ns = 1, int ne = n, int id = 0) {
    unlazy(id);
    if (qs > ne || qe < ns) return;
    if (qs <= ns && ne <= qe) {
        lazy[id] = lazy[id] * val, upd[id] = 1;
        unlazy(id);
        return;
    }
    int l = 2 * id + 1, r = 2 * id + 2, md = ns + (ne - ns) / 2;
    update(qs, qe, val, ns, md, l);
    update(qs, qe, val, md + 1, ne, r);
    Tree[id] = Tree[l] + Tree[r];
}

int query(int qs, int qe, int ns = 1, int ne = n, int id = 0) {
    unlazy(id);
    if (qs > ne || qe < ns) return 0;
    if (qs <= ns && ne <= qe)return Tree[id].a[0][1];
    int l = 2 * id + 1, r = 2 * id + 2, md = ns + (ne - ns) / 2;
    return merge(query(qs, qe, ns, md, l), query(qs, qe, md + 1, ne, r));
}


void Solve() {
    int q;
    cin >> n >> q;
    fib.a[0][0] = 0;
    fib.a[1][0] = fib.a[0][1] = fib.a[1][1] = 1;
    m.a[0][0] = m.a[1][1] = 1;

    for (int i = 0; i < 4 * N; i++)lazy[i] = Tree[i] = m;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        update(i, i, expo_power(fib, x));
    }
    
    while (q--) {
        int x, l, r;
        cin >> x >> l >> r;
        if (x == 1) {
            cin >> x;
            Matrix curr = expo_power(fib, x);
            update(l, r, curr);
        } else {
            cout << query(l, r) << endl;
        }

    }

}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}