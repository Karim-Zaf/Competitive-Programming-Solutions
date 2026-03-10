#include <bits/stdc++.h>
using namespace std ;
 
int main (){
    int l; cin >> l ; while (l--){
    int a;long long somme =0,maxim=0,j=0  ; cin >> a ; 
    long long tab[a][2];
    for ( int i = 0; i < a ; i ++){
        cin >> tab[i][0]>> tab[i][1];
        if (tab[i][0]>maxim || tab[i][1]>= maxim){
            maxim = max ( tab[i][0], tab[i][1]);
            j=i;
        }
    }
    somme += 2*( tab[j][0] + tab[j][1]);
    tab[j][0]=0; tab[j][1]=0;
    for ( int i = 0; i < a ; i ++)
        somme+= 2*min ( tab[i][0],tab[i][1]);
    cout << somme << endl;
 
}}