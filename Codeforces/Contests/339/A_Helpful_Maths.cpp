#include <bits/stdc++.h>
using namespace std ;
int main ()
{
    string ch; cin >> ch;
    int x= ch.length();
    int tab[x];
    for(int i =0; i <x ;i+=2)
        tab[i/2]=ch[i]-'0';
    sort (tab,tab+x/2+1);
    for(int i =0; i <x ;i+=2)
        ch[i]=char(tab[i/2]+'0'); cout << ch;
}