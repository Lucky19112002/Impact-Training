#include<bits/stdc++.h>
using namespace std;
int fact(int num){
    int fact=1;
    for (int i = 2; i <=num; i++)
    {
        fact*=i; 
    }
    return fact;
}


int main(){
    cout<<"Enter number ";
    int n,r;
    cin>>n>>r;
    int ans = fact(n)/(fact(r)*fact(n-r));
    cout<<ans;
    return 0;
}