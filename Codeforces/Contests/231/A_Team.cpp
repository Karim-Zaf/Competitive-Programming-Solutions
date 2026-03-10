#include <iostream>
using namespace std;
int main ()
{
    int nb,somme =0; cin >>nb;
    for (int i =0;i<nb;i++)
    {
        int s=0;
        for (int j =0;j<3; j++)
        {
                int a; cin>> a; s+=a;
        }
        if (s>=2)
            somme++;
    }
    cout << somme;
}
