#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    int n;
    n = 5;
    for (int i = 1 ;i<=n; i++)
    {
        for (int j = 1; j<=n+1-i; j++)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
/*
1 2 3 4 5
1 2 3 4
1 2 3
1 2
1
*/
