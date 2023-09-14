#include<bits/stdc++.h>
using namespace std;

int fact(int n){
    int fact =1;
    for(int i =2; i<=n;i++){
        fact*=i;
    }
    return fact;
}
int main(){
    cout<< "enter number";
    int a;
    cin>>a;

    for (int i = 0; i <a; i++)
    {
        for (int j = 0; j <=i; j++)
        {
            int ans = fact(i)/(fact(j)*fact(i-j));
            cout<<ans<<" ";
        }
        cout<<endl;
    }
    return 0;
}