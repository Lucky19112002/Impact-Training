#include<bits/stdc++.h>
using namespace std;
void fibo_series(int num){
    int t3;
    int t1 =0;
    int t2 =1;
    for (int i = 1; i <=num; i++)
    {
        cout<<t1<<",";
        t3 = t1+t2;
        t1=t2;
        t2=t3;
    }
    return;
}
int main(){
    cout<<"Enter number: ";
    int a;
    cin>>a;
    fibo_series(a);
}