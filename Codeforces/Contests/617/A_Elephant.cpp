#include <iostream>
using namespace std; 
int main ()
{
    int pas ; cin >> pas ;
    int x=5 , compteur =0;
    while(pas>0)
    {
        while (x> pas)
          x=x-1;
        pas =pas - x;
        compteur ++;
      
    }
    cout << compteur;

}