#include<bits/stdc++.h>
using namespace std;
int natural_number(int n){
    int a=0;
    for(int i=1;i<=n;i++){
        a+=i;
    }
    cout<<"Loop :"<<a<<endl;
    int b = (n*(n+1))/2;
    cout<<"Formula :"<<b;
}
int main(){
    cout<< "enter number ";
    int a;
    cin>>a;
    natural_number(a);
    return 0;
}