#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    int n;
    n = 5;
    for (int i = 1 ;i<=n; i++)
    {
        for (int j = 1; j<=n-i; j++)
        {
            cout<<"  ";  
        }
        for (int i = 1; i<=n; i++)
        {
            cout<<"* ";
        } 
        cout<<endl;
    }
    return 0;
}
/*
        * * * * *
      * * * * *
    * * * * *
  * * * * *
* * * * *
*/
