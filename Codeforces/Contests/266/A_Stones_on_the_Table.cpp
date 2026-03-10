#include <iostream>
#include <string>
#include <cctype>
using namespace std ;
int main ()
{
    int c,s=0 ; cin >>c;char one ='A';cin.ignore();
    while (c--){
        char two ; cin >> two ;
        if ( one == two) s++;// cout << "la charactere "<< one << " est egale a "<< two << " et c= "<<c+1<<endl;}
        one=two;
    }
    cout << s;

}