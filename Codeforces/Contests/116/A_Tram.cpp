#include <iostream>
using namespace std;
int main (){

    long long  n ,nb=0, res =0; cin >> n;
    for (int i=0; i <n ; i++){
        int a , b ;
        cin >> a >> b ;
        nb=nb-a+b;
        if ( nb> res)
            res=nb;
    }
    cout << res << endl;

}
