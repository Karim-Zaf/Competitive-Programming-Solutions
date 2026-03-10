#include <bits/stdc++.h>
using namespace std ;
int main ()
{
   int t ; cin >> t;
   while (t--){
       int k,b,somme=0,stock=0;string ch ; cin >> k>> ch;
       for (int i=0; i <k ; i++){
       cin>>b;
        if (ch[i]=='1') somme += max(stock,b);
        if (stock>b||ch[i]=='0')stock=b;}
        cout <<somme << endl;
       }}
      /*int n ,a,b,somme=0 ;string ch ;cin >>n ; cin.ignore();  cin >> ch; cin.ignore(); cin>>a;
      int stockpos =0,stock= a;
      for (int j=1; j<n; j++){
         cin >>b;
         if ((a>b && ch[j-1]=='0'&&ch[j]=='1')||stock>b){
            ch[j]='0';
            if (stock>b){
               // ch[stockpos]='1';somme+=stock;
                stock=b;stockpos=j;
            }
            else{
                ch[j-1]='1';somme+=a;
            }  
            //ch[j-1]='1';
            //cout << "haja" <<endl;
         }
         //else{stock=b;stockpos =j;}
         if (ch[j]=='1') somme+=b;
         else if (ch[j]==0 && b> stock){stock=b;stockpos=j;}
         a=b;
         //cout << ch<< endl;
      }
      if (ch[n-1]=='1')somme+=a;
      cout << somme<< endl;
   }*/
