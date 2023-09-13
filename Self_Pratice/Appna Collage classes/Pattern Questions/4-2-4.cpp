#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    int n,start;
    n = 4;

    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=n-i; j++)
        {
            cout<<"  ";
        }
        for (int j = 1; j <=2*i-1; j++)
        {
            cout<<"* ";
        }
        cout<<endl; 
    }
    for (int i = n; i >=1; i--)
    {
        for (int j = 1; j <=n-i; j++)
        {
            cout<<"  ";
        }
        for (int j = 1; j <=2*i-1; j++)
        {
            cout<<"* ";
        }
        cout<<endl; 
    }

/*
    for (int i = 1 ;i<=n; i++)
    {
        int j;
        for (j = 1; j<=n-i; j++)
        {
            cout<<"  ";
        }
        start = i;
        for (; j<=n; j++)
        {
            cout<<"* ";
        }
        start =2;
        for (; j<=n+i-1; j++)
        {
            cout<<"* ";
        }
        
        cout<<endl;
    }
    for (int i = n;i>=1; i--)
    {
        int j;
        for (j = 1; j<=n-i; j++)
        {
            cout<<"  ";
        }
        start = i;
        for (; j<=n; j++)
        {
            cout<<"* ";
        }
        start =2;
        for (; j<=n+i-1; j++)
        {
            cout<<"* ";
        }
        
        cout<<endl;
    }

    */
    return 0;
}
/*
      *       
    * * *     
  * * * * *   
* * * * * * * 
* * * * * * * 
  * * * * *   
    * * *     
      *  
*/
