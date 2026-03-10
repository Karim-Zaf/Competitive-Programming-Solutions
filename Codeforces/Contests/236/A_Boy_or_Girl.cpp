#include <iostream>
#include <string>
using namespace std;
int main ()
{
    int s=0,tab[26]={0}; string ch ; cin >> ch;
    for (int i =0 ; i < int (ch.length());i++)
    {
        if(tab[ch[i]-int('a')]==0)
        s++;
        tab[ch[i]-int('a')]++;
    }
    if (s%2==0)
        cout << "CHAT WITH HER!";
    else cout << "IGNORE HIM!";
}