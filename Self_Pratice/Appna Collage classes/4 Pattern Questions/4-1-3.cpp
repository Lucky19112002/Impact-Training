#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    int n;
    cin>>n;
    int col = n;
    for (int i = n; i >=1; i--)
    {
        for (int j = 1; j<=i; j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
    
    return 0;
}
/*
5
* * * * * 
* * * *   
* * *     
* *       
* 
*/