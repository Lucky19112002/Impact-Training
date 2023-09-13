#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"enter value: ";
    cin>>n;
    int reverse =0;
    while (n>0)
    {
        int lastdigit = n%10;
        reverse = reverse*10 + lastdigit; //4*10 = 40  >> 40+3 == 43.
        n=n/10;
    }
    cout<<reverse;
    return 0;
}