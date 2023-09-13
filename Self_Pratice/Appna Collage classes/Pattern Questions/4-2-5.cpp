#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    int n;
    n = 9;
    int row=3;
    for (int i = 1 ;i<=row; i++)
    {
        for (int j = 1; j<=n; j++)
        {
            if((i+j)%4 == 0)
            {
                cout<<"* ";
            }
            else if (i == 2 && j%4 == 0)
            {
                cout<<"* ";
            }
            
            else{
                cout<<"  ";
            }
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
