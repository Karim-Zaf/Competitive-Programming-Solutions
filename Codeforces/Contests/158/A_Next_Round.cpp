#include <iostream>
using namespace std;
int main ()
{
    int tab[50],s=0,n,k,j=1; cin >>n>>k;
    for (int i=0; i < n; i++)
        cin >> tab[i];
        if (tab[0]>=tab[k-1]&&tab[0]!=0)
        s++;
    while((j<k||tab[j-1]==tab[j])&&tab[j]!=0)
    {
        j++;s++;
    }

    cout << s;
}