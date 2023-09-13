#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    int n;
    n = 5;
    for (int i = 1 ;i<=n; i++)
    {
        for (int j = 1; j<=i; j++)
        {
            cout<<"* "; 
        }
        int space = 2*n-2*i;
        for (int i = 1; i <= space; i++)
        {
            cout<<"  ";
        }
        for (int j = 1; j<=i; j++)
        {
            cout<<"* "; 
        }
        cout<<endl;
    }

    for (int i = n ;i>=1; i--)
    {
        for (int j = 1; j<=i; j++)
        {
            cout<<"* "; 
        }
        int space = 2*n-2*i;
        for (int i = 1; i <= space; i++)
        {
            cout<<"  ";
        }
        for (int j = 1; j<=i; j++)
        {
            cout<<"* "; 
        }
        cout<<endl;
    }
    return 0;
}
/*
*                 * 
* *             * * 
* * *         * * * 
* * * *     * * * * 
* * * * * * * * * * 
* * * * * * * * * * 
* * * *     * * * * 
* * *         * * * 
* *             * *
*                 *
*/
