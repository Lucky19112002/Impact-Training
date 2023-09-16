#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,maxNo=0,minNO=0;
    cout<<"Enter length: ";
    cin >>n;
    int a[n];

    for (int i = 0; i <n; i++)
    {
        cout<<"a["<<i<<"]: ";
        cin>>a[i];
    }
    maxNo = INT_MIN;
    minNO = INT_MAX;
    for (int i = 0; i <n; i++)
    {
        maxNo = max(maxNo,a[i]);
        //     maxNo = a[i];
        // }
        minNO = min(minNO,a[i]);
        // if(a[i]>maxNo){
        // if(a[i]<minNO){
        //     minNO= a[i];
        // }
    }
    cout<<"max: "<<maxNo<<endl<<"min: "<<minNO;
    return 0;
}