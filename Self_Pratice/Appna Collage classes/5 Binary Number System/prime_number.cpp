#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"enter value: ";
    cin>>n;
    bool flag =0;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i ==0){
            cout<<"Not Prime";
            flag=1;
            break;
        }
    }
    if (!flag)
    {
        cout<<"Prime";
    }
    return 0;
}