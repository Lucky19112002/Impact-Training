#include<bits/stdc++.h>
using namespace std;

int conversion(int n){
    int ans = 0;
    int x = 1;
    while (n>0)
    {
        int y= n%10; // Last digite of number
        ans+= x*y;
        x*=2;
        n /= 10; // remove Last  number
    }
    return ans;
}

int main(){
    int n;
    cout<<"enter ";
    cin>>n;
    cout<< conversion(n);
    return 0;
}