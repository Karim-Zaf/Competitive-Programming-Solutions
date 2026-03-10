#include <bits/stdc++.h>
using namespace std ;

struct info {
    int a , b;
};
info tab[30];
int main()
{
    int n, s=0; cin >> n ;int k=n,r=n;
    while (n--){
        cin >> tab[n-1].a >> tab[n-1].b;
    }
    while ( k--){
        int z=r;
        while (z--){
        if (tab[k-1].a==tab[z-1].b && z!=k)
            s++;
            //cout << tab[k-1].a << "  " << tab[z-1].b <<endl;}
        }
    }
cout << s;
}